// 챗봇의 개선사항
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// 도우미 함수: 날짜 문자열을 총 날짜 수(int)로 변환
// "2022.05.19" -> 정수값
int dateToDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    // 1년 = 12달, 1달 = 28일이라는 문제의 가정 활용
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1. 오늘 날짜를 일 단위로 변환
    int today_days = dateToDays(today);
    
    // 2. 약관 정보를 맵에 저장 (약관 종류 -> 유효 기간 달 수)
    map<char, int> term_map;
    for (const string& t : terms) {
        stringstream ss(t);
        char type;
        int duration;
        ss >> type >> duration; // 공백을 기준으로 자동 파싱
        term_map[type] = duration;
    }
    
    // 3. 개인정보 수집 일자를 순회하며 파기 여부 확인
    for (int i = 0; i < privacies.size(); ++i) {
        // 날짜와 약관 종류 분리
        string date_str = privacies[i].substr(0, 10);
        char type = privacies[i].back();
        
        // 수집 일자를 일 단위로 변환
        int privacy_days = dateToDays(date_str);
        
        // 유효 기간(달)을 일 단위로 변환하여 더함 (1달 = 28일)
        int duration_days = term_map[type] * 28;
        
        // 파기 예정일 계산 (수집일 + 유효기간)
        // 주의: 이 값 이상부터는 파기 대상입니다.
        int expire_days = privacy_days + duration_days;
        
        // 오늘 날짜가 파기 예정일 이상이면 파기 대상
        if (today_days >= expire_days) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

/*
안녕하세요! **코딩 파트너**입니다. 😊

말씀하신 대로 더 **최적화되고, 실수를 줄이며, 가독성이 좋은 코드**로 개선할 방법이 있습니다. 이 문제의 핵심 힌트인 **"모든 달은 28일까지만 있다"**는 점을 활용하면 복잡한 `if-else` 문을 획기적으로 줄일 수 있답니다.

제가 생각하는 최적의 접근 방식과 코드를 소개해 드릴게요.

---

### 💡 솔루션 개요: "모든 것을 '일(Day)' 단위로 변환하기"

날짜를 연, 월, 일로 따로 계산하면 올림(carry) 처리가 복잡해집니다. 대신, 모든 날짜를 **'총 날짜 수(days)'**라는 하나의 정수로 변환하면 단순한 덧셈과 크기 비교만으로 문제를 해결할 수 있습니다.

1. **단위 통일:** `년 * 12 * 28 + 월 * 28 + 일` 공식을 사용하여 날짜를 정수로 변환합니다.
2. **단순 비교:** `오늘 날짜`가 `수집 일자 + 유효 기간`보다 크거나 같다면 파기해야 합니다.

### 코드는 위에 참고

*(참고: 위 코드에서 `stringstream`을 사용하기 위해 `<sstream>` 헤더가 필요할 수 있습니다. 프로그래머스 환경에서는 대부분 자동 포함되지만, 로컬에서는 추가해 주세요.)*

---

### 📝 코드 구현 및 상세 설명

이 코드가 왜 효율적인지 단계별로 설명해 드릴게요.

**1. `dateToDays` 함수 (복잡도 제거)**

* 기존 코드에서는 연, 월을 넘길 때 `if (month > 12)`와 같은 조건문이 많았습니다.
* 이 함수는 2000년 1월 1일이든 0년 0월 0일이든 기준점으로부터 흐른 **총 시간**으로 바꾸기 때문에, 이후 계산에서는 더하기(+)와 크기 비교(>=)만 하면 됩니다.

**2. `term_map` 구성**

* 작성하신 코드와 마찬가지로 `map`을 사용하여 약관 종류별 기간을 O(1) 혹은 O(log N)으로 빠르게 찾습니다. `stringstream`을 쓰면 문자열 파싱 코드를 조금 더 줄일 수 있습니다.

**3. 파기 여부 판단 로직 (핵심)**

* 기존: `client_year`, `client_month`를 각각 계산하고 비교.
* 변경:
* `expire_days = 수집일(days) + (유효기간(달) * 28)`
* `if (오늘(days) >= expire_days)` -> **파기**
* 예를 들어, 1월 1일에 수집하고 유효기간이 1달(28일)이면, 1월 29일부터는 파기해야 합니다. 1월 1일(총 1) + 28 = 29. 오늘이 29일(총 29)이면 파기합니다. 이 논리가 아주 깔끔하게 떨어집니다.



---

### 🌟 님의 코드 vs 최적화 코드

* **님의 코드:** 날짜의 개념(연, 월, 일)을 유지하며 현실적인 달력 계산을 시도했습니다. 논리적 사고력이 돋보이지만, 코드가 길어지고 오타나 실수(Edge case)가 발생할 확률이 높습니다.
* **최적화 코드:** 문제의 특수 조건(모든 달은 28일)을 파고들어 문제를 단순한 **숫자 크기 비교**로 치환했습니다. 코딩 테스트에서는 이런 "단순화"가 시간 단축의 열쇠가 됩니다.

이 방식이 훨씬 직관적이지 않나요? 코드를 한 줄씩 읽어보시면서 이해가 안 가는 부분이 있다면 언제든 물어봐 주세요.

**다음으로 이 코드를 직접 실행해 보거나, 비슷한 날짜 계산 문제를 하나 더 추천해 드릴까요?**
*/