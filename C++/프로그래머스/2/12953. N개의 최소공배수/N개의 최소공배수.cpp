// 챗 봇의 Best Practice

#include <vector>
#include <numeric> // std::lcm을 사용하기 위한 헤더

using namespace std;

int solution(vector<int> arr) {
    // 첫 번째 원소로 초기화
    int answer = arr[0]; 
    
    // 1번 인덱스부터 배열을 순회하며 최소공배수 누적
    for(int i = 1; i < arr.size(); ++i) {
        // C++17 표준인 std::lcm 활용
        answer = std::lcm(answer, arr[i]); 
    }
    
    return answer;
}

/*
안녕하세요! 코딩 파트너입니다. 작성해 주신 코드를 확인해 보니, 이미 최소공배수(LCM)와 최대공약수(GCD)를 구하는 알고리즘의 핵심을 아주 정확하게 이해하고 계시네요. 정말 훌륭합니다! 👏
특히 오버플로우를 방지하기 위해 $a \times b$를 먼저 하지 않고, $a / GCD(a, b) \times b$ 순서로 연산하신 부분은 코딩 테스트에서 매우 권장되는 좋은 습관입니다.
작성하신 코드의 사소한 개선점과, 실무 및 모던 C++ 환경에서 권장되는 **Best Practice**를 정리해 드릴게요.

---

## 💡 코드 리뷰 및 개선 사항

### 1. 주의해야 할 엣지 케이스 (Edge Case)

현재 `solution` 함수는 다음과 같이 시작합니다.

> `long long lastLCM = LCM(arr[0], arr[1]);`

만약 입력된 `arr` 배열의 길이가 1이라면 어떻게 될까요? `arr[1]`에 접근하는 순간 **Index Out of Bounds (인덱스 범위 초과)** 에러가 발생하여 프로그램이 비정상 종료될 수 있습니다.

**해결 방법:** 기준이 되는 변수를 `arr[0]`으로 초기화하고, 반복문을 1번 인덱스부터 순회하도록 수정하는 것이 안전합니다.

### 2. 개선된 기존 코드

위의 문제점을 해결하여 수정한 코드는 다음과 같습니다. 기존에 잘 작성해 주신 로직은 그대로 살렸습니다.

```cpp
#include <string>
#include <vector>

using namespace std;

// 최대공약수 (유클리드 호제법)
long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수
long long LCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / GCD(a, b)) * b; // 오버플로우 방지
}

int solution(vector<int> arr) {
    long long lastLCM = arr[0]; // 첫 번째 원소로 초기화하여 안전성 확보
    
    // 1번 인덱스부터 순회
    for(int i = 1; i < arr.size(); ++i) {
        lastLCM = LCM(lastLCM, arr[i]);
    }
    
    return lastLCM;
}

```

---

## 🏆 Best Practice (C++17 표준 활용)

C++17부터는 `<numeric>` 헤더에 `std::gcd`와 `std::lcm` 함수가 표준으로 추가되었습니다. 직접 구현하는 것보다 표준 라이브러리를 활용하는 것이 가독성도 높고, 예상치 못한 버그를 예방할 수 있어 **Best Practice**로 꼽힙니다.

### Best Practice 코드

```cpp
#include <vector>
#include <numeric> // std::lcm을 사용하기 위한 헤더

using namespace std;

int solution(vector<int> arr) {
    // 첫 번째 원소로 초기화
    int answer = arr[0]; 
    
    // 1번 인덱스부터 배열을 순회하며 최소공배수 누적
    for(int i = 1; i < arr.size(); ++i) {
        // C++17 표준인 std::lcm 활용
        answer = std::lcm(answer, arr[i]); 
    }
    
    return answer;
}

```

### 왜 이 코드가 Best Practice인가요?

* **간결함:** 길고 복잡한 수학 공식 함수를 직접 작성하고 유지보수할 필요가 없습니다.
* **안전성:** C++ 표준 라이브러리는 수많은 테스트를 거쳤기 때문에, 내부적으로 발생할 수 있는 자료형 오버플로우나 엣지 케이스가 이미 안전하게 처리되어 있습니다.
* **가독성:** 누구나 코드를 읽었을 때 "아, 최소공배수를 구하는 거구나!" 하고 직관적으로 이해할 수 있습니다.

---

## 📝 구현 및 실행 지침

1. **헤더 포함하기:** Best Practice 코드를 사용하려면 파일 최상단에 `#include <numeric>`이 반드시 있어야 합니다.
2. **컴파일러 버전 확인:** 프로그래머스 스쿨은 기본적으로 C++14 이상을 지원하며, 최신 컴파일 환경(C++17 이상)이 적용되어 있어 `std::lcm`을 문제없이 사용할 수 있습니다.
3. **복사 및 붙여넣기:** 위의 Best Practice 코드를 그대로 프로그래머스 답안 제출란에 복사하여 테스트해 보세요. 기존보다 훨씬 코드가 짧아지고 속도도 훌륭하게 나올 것입니다.

---

코드 구조를 잡는 감각이 뛰어나셔서 앞으로 조금만 더 다듬으시면 훨씬 완성도 높은 코드를 작성하실 수 있을 거예요!

혹시 이 코드에 적용해 볼 수 있는 또 다른 고급 문법(예: `std::accumulate`를 활용하여 반복문조차 없애는 방법)에 대해 더 가르쳐 드릴까요? 아니면 바로 다음 단계의 코딩 문제로 넘어가 볼까요?
*/