// 챗봇의 개선사항
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1. 결과를 담을 벡터 초기화 (모든 유저 수만큼 0으로)
    vector<int> answer(id_list.size(), 0);
    
    // 2. ID를 인덱스로 매핑 (빠른 조회를 위해)
    // 예: "muzi" -> 0, "frodo" -> 1
    unordered_map<string, int> id_idx;
    for(int i = 0; i < id_list.size(); ++i) {
        id_idx[id_list[i]] = i;
    }
    
    // 3. 신고 기록 저장 (중복 신고 자동 제거를 위해 unordered_set 사용)
    // Key: 신고당한 사람, Value: 신고한 사람들의 집합
    unordered_map<string, unordered_set<string>> report_log;
    
    for(const string& r : report) {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        
        // set은 중복된 값이 들어오면 자동으로 무시합니다.
        report_log[reported].insert(reporter);
    }
    
    // 4. 신고 횟수가 k 이상인 경우, 신고한 사람에게 메일 보내기
    for(auto& entry : report_log) {
        string reported = entry.first;
        unordered_set<string>& reporters = entry.second;
        
        // 해당 유저를 신고한 사람의 수가 k 이상이라면
        if(reporters.size() >= k) {
            for(const string& reporter : reporters) {
                // 신고한 사람의 인덱스를 찾아 결과 벡터 증가
                int idx = id_idx[reporter];
                answer[idx]++;
            }
        }
    }
    
    return answer;
}

/*
### 🔍 작성하신 코드 리뷰

**잘한 점:**

* **문제 이해도:** 누가 누구를 신고했는지, 그리고 신고 횟수가 번 이상인지 확인하여 메일을 발송하는 로직을 정확하게 구현하셨습니다.
* **자료구조 활용:** `unordered_map`을 사용하여 ID와 신고 정보를 매핑한 것은 좋은 선택입니다.

**개선하면 좋은 점:**

1. **중복 신고 처리의 효율성:**
    * 현재 `vector`와 `find`를 사용하여 중복 신고를 확인하고 있습니다. `vector`에서 `find`를 사용하는 것은 $O(N)$의 시간 복잡도를 가집니다.
    * 한 유저가 매우 많은 신고를 당했을 때, 매번 벡터를 처음부터 끝까지 검색해야 하므로 시간이 오래 걸릴 수 있습니다.
    * 이를 `unordered_set`이나 `set`으로 변경하면 중복 검사를 $O(1) 또는 $O(\log N)$으로 줄일 수 있습니다.
    
2. **문자열 파싱:**
    * `substr`은 매번 새로운 문자열 객체를 생성하므로 메모리와 시간을 소모합니다. `stringstream`을 사용하거나, 단순히 공백 위치만 찾아서 처리하는 방식은 유지하되 중복 제거를 먼저 하는 것이 유리합니다.

3. **결과 처리:**
    * 마지막에 `mailCount` 맵을 다시 `answer` 벡터로 옮기는 과정이 있습니다. 처음에 ID 별로 인덱스(순서)를 저장해 두면, `answer` 벡터의 해당 인덱스 값을 직접 증가시킬 수 있어 코드가 더 간결해집니다.



---

### ✨ 최적화된 코드 제안

이 방식은 `unordered_set`을 사용하여 중복 신고를 자동으로 무시하고, ID와 인덱스를 매핑하여 결과를 빠르게 저장하는 방식입니다.

### 💡 코드 구현 및 이해 가이드

이 최적화된 코드가 어떻게 작동하는지 단계별로 설명해 드릴게요.

1. **ID 인덱싱 (`id_idx` 맵):**
    * 나중에 결과를 `answer` 벡터에 순서대로 넣어야 하죠? 문자열 ID로는 벡터의 몇 번째 칸인지 바로 알 수 없으니, 미리 `{"muzi": 0, "frodo": 1 ...}` 처럼 번호를 매겨둡니다. 이렇게 하면 마지막에 $O(1)$로 접근할 수 있습니다.

2. **중복 제거를 위한 `unordered_set`:**
    * 작성하신 코드에서는 `vector`를 순회하며 중복을 찾았지만, 여기서는 `unordered_map<string, unordered_set<string>>`을 썼습니다.
    * `report_log[신고당한사람].insert(신고한사람)`을 하면, 같은 사람이 여러 번 신고해도 `unordered_set`의 특성상 딱 한 번만 저장됩니다. 코드가 훨씬 간결해지고 빨라집니다.

3. **메일 발송 카운트:**
    * `report_log`를 순회하면서, 신고자 명단(`reporters`)의 크기(`.size()`)가  이상인지 확인합니다.
    * 조건을 만족하면 명단에 있는 사람들의 인덱스를 `id_idx`에서 찾아 `answer` 값을 1씩 올려줍니다.


이 방식은 데이터 양이 많아져도 검색 속도가 빠르기 때문에 효율적입니다.

작성하신 코드도 충분히 훌륭했지만, **자료구조(Set)의 특성**을 활용하면 코드를 더 줄이고 성능을 높일 수 있다는 점을 기억해 주시면 좋을 것 같아요!
*/