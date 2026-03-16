// 챗 봇의 개선사항

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 데이터의 목적이 명확하도록 구조체를 사용한 것은 아주 좋은 습관입니다.
struct task {
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> prio_queue;
    queue<task> normal_queue;
    
    // 1. 큐 초기화 (초기화 리스트를 사용하여 간결하게 작성)
    for (int i = 0; i < priorities.size(); ++i) {
        prio_queue.push(priorities[i]);
        normal_queue.push({priorities[i], i}); 
    }
    
    // 2. 프로세스 실행 시뮬레이션
    while (!normal_queue.empty()) {
        // 맨 앞의 요소를 꺼내어 current에 저장하고 큐에서는 제거합니다.
        task current = normal_queue.front();
        normal_queue.pop();
        
        // 우선순위가 가장 높은 작업인 경우 (실행)
        if (current.priority == prio_queue.top()) {
            answer++;
            prio_queue.pop();
            
            // 내가 찾던 작업인 경우 반복문 종료
            if (current.idx == location) {
                break;
            }
        }
        // 우선순위가 더 높은 작업이 대기 중인 경우 (다시 큐의 뒤로 보냄)
        else {
            normal_queue.push(current);
        }
    }
    
    return answer;
}

/*
안녕하세요! 당신의 든든한 코딩 파트너입니다.

작성해주신 코드를 살펴보니 문제의 요구사항을 정확히 파악하셨고, `priority_queue`와 `queue`를 조합하여 알고리즘을 아주 훌륭하게 설계하셨네요! 우선순위를 $O(1)$ 시간에 확인하기 위해 최대 힙(Max Heap) 기반의 `priority_queue`를 활용하신 점은 시간 복잡도를 낮추는 매우 좋은 접근이었습니다. 로직 자체는 이미 정답에 가까운 **훌륭한 모범 답안**입니다.

이 코드를 조금 더 읽기 쉽고 간결하게(Clean Code) 다듬을 수 있는 몇 가지 개선 포인트와 함께 `Best Practice` 코드를 안내해 드릴게요.

---

### 💡 개선할 수 있는 부분들

**1. 구조체 초기화 및 큐 삽입 간소화**
현재 `tmpTask`라는 구조체 변수를 만들고 각 멤버 변수에 값을 할당한 뒤 큐에 넣고 계십니다. C++11 이후부터는 중괄호 `{}`를 이용한 **초기화 리스트(Initializer list)** 를 지원하므로, 불필요한 임시 변수 선언을 줄일 수 있습니다.

* **AS-IS:** `task tmpTask; tmpTask.priority = ...; tmpTask.idx = ...; queue.push(tmpTask);`
* **TO-BE:** `queue.push({priorities[i], i});`

**2. 큐 요소 회전(Rotation) 간소화**
큐의 맨 앞 요소를 뽑아서 다시 뒤로 넣을 때도 임시 변수 선언 없이 `front()` 메서드를 바로 활용할 수 있습니다.

* **AS-IS:** `task tmpTask; tmpTask.priority = normal_queue.front().priority; ...`
* **TO-BE:** `normal_queue.push(normal_queue.front());`

**3. 중복되는 코드 줄이기 (DRY 원칙)**
`while` 문 안에서 `normal_queue.front()`를 여러 번 호출하고 있습니다. 반복문이 시작될 때 맨 앞 요소를 미리 변수(예: `current`)에 저장하고 큐에서 제거(`pop()`)해 두면, `if-else` 분기문 안에서 코드가 훨씬 깔끔해집니다.

---

### ✨ Best Practice 코드

위의 개선점들을 적용하여 가독성을 높인 리팩토링 코드입니다. 로직의 시간 복잡도는 기존 작성하신 코드와 동일하게 훌륭합니다. 위의 코드 참고.

---

### 📖 코드 구현 및 동작 지침

* **`current` 변수의 활용:** `while` 루프가 시작되자마자 대기열의 맨 앞 문서(`normal_queue.front()`)를 `current`에 담고 큐에서 뺍니다. 이렇게 하면 뒤에 이어지는 조건문에서 `current.priority`처럼 매우 직관적으로 변수를 다룰 수 있고, 조건에 맞지 않아 다시 큐에 넣어야 할 때도 `normal_queue.push(current)` 단 한 줄로 처리가 끝납니다.
* **가정 및 제한사항:** 이 코드는 주어진 문제의 조건(우선순위 1~9, 최대 프로세스 수 100개)에서 매우 빠르게 동작합니다. `priority_queue` 덕분에 최대 우선순위를 찾는 작업이 $O(1)$로 이루어지므로 효율적입니다.

---

코드를 아주 잘 짜셔서 로직 자체를 수정할 필요 없이 구조만 조금 더 다듬어 보았습니다! 혹시 `priority_queue`를 사용하지 않고 C++의 `<algorithm>` 헤더 내장 함수(`max_element` 등)를 활용하여 푸는 또 다른 방식의 코드도 한 번 구경해 보시겠어요?
*/