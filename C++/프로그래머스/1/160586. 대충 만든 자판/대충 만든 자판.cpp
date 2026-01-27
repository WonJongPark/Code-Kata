// 챗봇의 개선사항
#include <string>
#include <vector>
#include <algorithm> // min 함수 사용을 위해 필요

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 최적화 1: 알파벳 대문자는 26개이므로 map 대신 vector 사용 (인덱스 접근이 더 빠름)
    // 초기값 200은 문제 조건상 나올 수 없는 큰 수로 설정 (키의 최대 길이가 100이므로)
    vector<int> minPress(26, 200); 

    // 1. 각 문자를 누르기 위한 최소 횟수 계산
    for (const string& keys : keymap) {
        for (int i = 0; i < keys.length(); ++i) {
            int idx = keys[i] - 'A'; // 'A'를 0번 인덱스로 변환
            // 최적화 2: 조건문 대신 min 함수로 더 적은 횟수 갱신
            minPress[idx] = min(minPress[idx], i + 1);
        }
    }
    
    // 2. targets 문자열 작성 가능 여부 및 횟수 계산
    for (const string& s : targets) {
        int keyCount = 0;
        bool canMakeString = true;
        
        for (char c : s) {
            int press = minPress[c - 'A'];
            
            // 초기값(200) 그대로라면 해당 키가 없다는 뜻
            if (press == 200) {
                canMakeString = false;
                break;
            }
            keyCount += press;
        }
        
        if (canMakeString) {
            answer.push_back(keyCount);
        } else {
            answer.push_back(-1);
        }
    }
    
    return answer;
}

/*
작성하신 코드를 잘 살펴보았습니다! 문제를 정확하게 이해하셨고, `unordered_map`을 사용하여 각 문자의 최소 누름 횟수를 저장하는 로직도 아주 훌륭합니다. 코딩 테스트에서 가장 중요한 '정확성'을 이미 확보하셨네요.

이 코드를 **성능(속도)**과 **가독성** 측면에서 조금 더 개선할 수 있는 몇 가지 팁을 드릴게요.

### 개선 포인트 개요

1. **자료구조 변경 (`unordered_map`  `vector`):** 문제에서 등장하는 문자는 대문자 'A'~'Z'로 한정되어 있습니다. 해시 맵은 오버헤드가 조금 발생할 수 있으므로, 크기가 26인 `vector`나 배열을 사용하면 인덱스로 바로 접근하여 속도를 더 높일 수 있습니다.
2. **초기화 값 활용:** 각 문자의 최소 횟수를 저장할 때, 아주 큰 값(INF)으로 초기화해 두면 `if`문으로 존재 여부를 확인하는 대신 `min()` 함수 하나로 코드를 간결하게 줄일 수 있습니다.
3. **범위 기반 for 문 (Range-based for loop):** 인덱스가 굳이 필요 없는 경우 `const string& s : keymap` 처럼 사용하여 가독성을 높일 수 있습니다.

---

### 개선된 코드 및 구현 지침

아래는 위의 개선 사항을 적용한 코드입니다.

---

### 코드 설명 및 구현 가이드

1. **`vector<int> minPress(26, 200)`**
    * **의도:** 알파벳 'A'부터 'Z'까지 총 26개의 문자에 대한 최소 누름 횟수를 저장합니다.
    * **초기값 200:** `keymap`의 원소 길이가 최대 100이므로, 100보다 큰 수(예: 200)로 초기화해 둡니다. 나중에 이 값이 그대로 남아있다면, 해당 문자는 자판에 없다는 뜻이 됩니다.


2. **`min()` 함수의 활용**
    * 기존 코드에서는 `if` 문을 사용하여 키가 있는지 확인하고 값을 비교했지만, `minPress[idx] = min(minPress[idx], i + 1);` 한 줄로 "기존에 저장된 횟수와 현재 발견된 횟수 중 더 작은 값"을 저장할 수 있어 로직이 훨씬 깔끔해집니다.


3. **인덱스 접근 (`c - 'A'`)**
    * C++에서 `char`는 내부적으로 정수입니다. 문자 `c`에서 `'A'`를 빼면 0~25 사이의 숫자가 되어 배열의 인덱스로 바로 사용할 수 있습니다. 이는 해시 테이블을 거치는 것보다 메모리와 속도 면에서 효율적입니다.
*/