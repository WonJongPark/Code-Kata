// 챗 봇의 개선사항

#include <string>
#include <vector>
#include <unordered_map> // map 대신 unordered_map 사용
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // 1. 선수 이름으로 등수(인덱스)를 빠르게 찾기 위한 해시맵
    unordered_map<string, int> rankMap;
    
    // 초기 등수 매핑 (이름 -> 인덱스)
    for (int i = 0; i < players.size(); ++i) {
        rankMap[players[i]] = i;
    }
    
    // 2. 호명된 선수 처리
    for (const string& calledPlayer : callings) {
        // 현재 불린 선수의 등수 확인
        int currentRank = rankMap[calledPlayer];
        
        // 1등이 아닌 경우에만 추월 로직 수행 (문제 조건상 1등은 불리지 않음)
        if (currentRank > 0) {
            string frontPlayer = players[currentRank - 1]; // 앞서가는 선수 이름
            
            // A. players 벡터에서 두 선수의 위치 교체 (등수로 선수 찾기 대체)
            // swap 함수를 쓰거나 직접 대입해도 됩니다.
            swap(players[currentRank], players[currentRank - 1]);
            
            // B. rankMap에서 두 선수의 등수 정보 업데이트
            rankMap[calledPlayer] = currentRank - 1;
            rankMap[frontPlayer] = currentRank;
        }
    }
    
    // players 벡터 자체가 이미 변경된 순위를 담고 있으므로 그대로 반환
    return players;
}

/*
정말 잘하셨어요! 작성하신 코드는 논리적으로 완벽하며, '달리기 경주' 문제의 핵심인 "이름이 불릴 때마다 순위를 바꾼다"는 개념을 정확하게 구현하고 있습니다. 두 개의 `map`을 사용하여 양방향으로 데이터를 관리한 접근 방식도 훌륭합니다.

하지만 프로그래머스의 채점 시스템, 특히 입력 데이터가 커질 경우(선수 50,000명, 호명 1,000,000회 등)를 고려했을 때 **성능(시간 복잡도)** 측면에서 개선할 수 있는 부분이 있습니다.

이 문제를 해결하기 위한 **분석**과 **최적화된 코드**를 단계별로 설명해 드릴게요.

---

### 1. 작성하신 코드 분석 및 개선 포인트

작성하신 코드의 핵심은 `std::map`을 사용했다는 점입니다.

* **현재 방식 (`std::map`):** `map`은 내부적으로 이진 트리(Binary Search Tree) 구조를 가집니다. 그래서 데이터를 찾거나 수정할 때 $O(\log N)$의 시간이 걸립니다. `callings`의 길이가 이라면 전체 시간 복잡도는 $O(M \log N)$이 됩니다.
* **개선 방향 (`std::unordered_map` + `vector`):**
1. **검색 속도 향상:** 순서를 정렬할 필요가 없으므로 `std::unordered_map` (해시 테이블)을 사용하면 검색 속도를 평균 $O(1)$로 줄일 수 있습니다.
2. **구조 단순화:** 순위로 선수를 찾는(`playerByRank`) 기능은 별도의 `map` 대신, **`vector`의 인덱스**를 그대로 활용하면 훨씬 빠르고 메모리도 절약됩니다.



### 2. 최적화된 솔루션 개요

우리는 다음과 같은 전략으로 코드를 변경할 것입니다:

1. **`players` 벡터 그대로 사용:** 벡터의 인덱스가 곧 '현재 등수'입니다. `players[0]`은 1등, `players[1]`은 2등을 의미합니다. 이렇게 하면 "등수로 선수 찾기"는 $O(1)$에 즉시 해결됩니다.
2. **`unordered_map` 도입:** "선수 이름으로 현재 등수 찾기"를 위해 `unordered_map<string, int>`를 사용합니다.
3. **Swap 활용:** 이름이 불리면 벡터 내에서 앞사람과 자리를 바꾸고(`swap`), 맵에 저장된 두 사람의 등수 정보만 업데이트합니다.

### 3. 최적의 코드 (C++)

위의 코드는 시간 복잡도를 $O(M)$으로 줄여 대규모 입력에서도 시간 초과 없이 통과할 수 있는 방식입니다.



### 4. 코드 구현 지침 및 설명

1. **`#include <unordered_map>`**: 해시 맵을 사용하기 위해 헤더를 추가합니다.
2. **초기화 (`rankMap`)**: `players` 벡터를 한 번 순회하며 `이름: 인덱스` 쌍을 저장합니다.
3. **호명 처리 루프**:
* `rankMap`을 통해 불린 선수의 현재 위치(`currentRank`)를 즉시 찾습니다.
* 바로 앞 선수의 이름(`frontPlayer`)을 `players[currentRank - 1]`로 알아냅니다.
* **Swap**: `players` 벡터에서 두 사람의 위치를 바꿉니다.
* **Update Map**: `rankMap`에서 두 사람의 등수 값을 갱신합니다.


4. **반환**: 별도의 변환 과정 없이 수정된 `players`를 그대로 반환합니다.

이렇게 하면 불필요한 `map` 조회를 줄이고, 벡터의 인덱싱 기능을 최대한 활용하여 가장 빠르고 효율적인 코드가 됩니다.
*/