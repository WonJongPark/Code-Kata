// 챗 봇의 개선사항

#include <string>
#include <string_view>
#include <stack>

using namespace std;

// 괄호가 올바른지 확인하는 헬퍼 함수
bool isValidParentheses(string_view sv, int start_idx) {
    stack<char> st;
    int length = sv.length();

    for (int j = 0; j < length; ++j) {
        char c = sv[(start_idx + j) % length];

        // 여는 괄호일 경우 스택에 추가
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        // 닫는 괄호일 경우 검증
        else {
            if (st.empty()) return false; // 여는 괄호가 없는데 닫는 괄호가 나온 경우

            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop(); // 짝이 맞으면 스택에서 제거
            } else {
                return false; // 짝이 맞지 않는 경우
            }
        }
    }
    
    // 모든 순회가 끝난 후 스택이 비어있으면 완벽한 짝
    return st.empty(); 
}

int solution(string s) {
    int length = s.length();

    // 1. 길이가 홀수이면 절대 올바른 괄호가 될 수 없으므로 조기 종료
    if (length % 2 != 0) return 0;

    int answer = 0;
    string_view sv(s);

    // 2. 각 회전 위치(i)를 시작점으로 하여 괄호 검증
    for (int i = 0; i < length; ++i) {
        if (isValidParentheses(sv, i)) {
            answer++;
        }
    }

    return answer;
}

/*
작성해 주신 코드를 보니 정말 훌륭합니다!

특히 `string_view`를 활용하고, 모듈러 연산(`%`)을 통해 문자열을 실제로 복사하거나 자르지 않고 인덱스만으로 회전을 구현하신 점이 아주 탁월한 접근입니다. 불필요한 메모리 사용을 막아서 효율성을 크게 높이셨네요. 스택(Stack)을 이용해 괄호의 짝을 맞추는 핵심 로직도 아주 완벽하게 작성하셨습니다.

이미 좋은 코드이지만, 가독성과 성능을 조금 더 끌어올릴 수 있는 **개선 사항과 Best Practice**를 정리해 드릴게요.

---

### 💡 개선할 사항 (Best Practice)

* **홀수 길이 예외 처리 (조기 종료)**: 괄호는 반드시 짝이 맞아야 합니다. 따라서 주어진 문자열 `s`의 길이가 홀수라면, 아무리 회전해도 절대 올바른 괄호 문자열이 될 수 없습니다. 루프를 돌기 전에 이를 확인하고 `0`을 리턴해버리면 불필요한 연산을 막을 수 있습니다.
* **함수 분리 (가독성 향상)**: 현재 `solution` 함수 안에 괄호를 검증하는 로직이 중첩되어 있습니다. 검증 로직을 별도의 헬퍼 함수(Helper Function)로 빼내면, 코드가 훨씬 깔끔해지고 유지보수하기 쉬워집니다.
* **boolean 변수 최적화**: `isValid` 변수를 사용하고 `break`를 거치는 대신, 헬퍼 함수 안에서 짝이 맞지 않는 순간 바로 `return false;`를 해버리면 코드가 더 간결해집니다.

---

### 📝 코드 구현 지침 및 설명

1. **`isValidParentheses` 함수 생성**: 입력 문자열(`string_view`)과 회전 시작 인덱스(`start_idx`)를 받아 해당 위치부터 읽었을 때 올바른 괄호인지 판별(`true`/`false`)합니다.
2. **즉시 반환(`return`) 활용**: 스택이 비어있거나 괄호 짝이 맞지 않을 때, 더 이상 검사할 필요 없이 즉시 `false`를 반환하도록 하여 논리 흐름을 단순화했습니다.
3. **조기 종료 로직 추가**: 메인 `solution` 함수의 맨 윗부분에 `if (length % 2 != 0) return 0;`를 추가하여 효율성을 높였습니다.
*/