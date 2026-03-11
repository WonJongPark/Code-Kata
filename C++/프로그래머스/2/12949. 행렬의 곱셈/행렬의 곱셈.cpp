// 챗 봇의 개선사항

#include <vector>

using namespace std;

// 1. 매개변수에 const와 참조자(&)를 사용하여 성능과 안전성을 높입니다.
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int arr1Row = arr1.size();
    int arr1Col = arr1[0].size();
    int arr2Col = arr2[0].size(); // arr2Row는 사용하지 않으므로 제거했습니다.
    
    // 2. 정답을 담을 2차원 벡터의 크기를 미리 할당하고, 모든 값을 0으로 초기화합니다.
    // 구조: vector<vector<int>> 이름(행의 개수, vector<int>(열의 개수, 초기값));
    vector<vector<int>> answer(arr1Row, vector<int>(arr2Col, 0));
    
    for (int i = 0; i < arr1Row; ++i) {
        for (int j = 0; j < arr2Col; ++j) {
            for(int k = 0; k < arr1Col; ++k) {
                // 3. answer가 이미 0으로 채워져 있으므로, 값을 바로 누적해서 더해줍니다.
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}

/*
### 💡 코드 개선을 위한 3가지 포인트

**1. 불필요한 메모리 복사 방지 (Pass by Const Reference)**

* **현재 상태:** `solution(vector<vector<int>> arr1, ...)` 처럼 매개변수를 선언하면, 함수가 실행될 때마다 원본 행렬의 모든 데이터가 메모리에 새로 복사됩니다. 행렬이 커질수록 시간이 오래 걸립니다.
* **Best Practice:** `solution(const vector<vector<int>>& arr1, ...)` 처럼 참조자(`&`)를 사용하면 복사 없이 원본을 직접 참조하게 되어 속도가 훨씬 빨라집니다. `const`를 붙이면 실수로 원본 데이터를 수정하는 것을 막아주어 안전성도 높아집니다.

**2. 벡터 크기 미리 할당하기 (Pre-allocation)**

* **현재 상태:** `push_back` 함수는 벡터에 빈 공간이 없을 때마다 새로운 메모리를 할당하고 기존 데이터를 이사시키는 작업을 합니다.
* **Best Practice:** 행렬의 곱셈에서 $M \times K$ 행렬과 $K \times N$ 행렬을 곱하면 결과는 항상 $M \times N$ 크기의 행렬이 됩니다. 처음부터 `answer` 벡터의 크기를 `arr1Row` $\times$ `arr2Col` 로 만들어두고 모든 칸을 0으로 초기화해 두면, `push_back`이나 `tempRow` 없이 인덱스(`answer[i][j]`)로 바로 접근해서 값을 더할 수 있습니다.

**3. 사용하지 않는 변수 정리**

* **현재 상태:** `int arr2Row = arr2.size();` 를 선언하셨지만 코드 내에서 사용되지 않았습니다.
* **Best Practice:** 행렬의 곱셈 조건 상 `arr1`의 열 개수(`arr1Col`)와 `arr2`의 행 개수(`arr2Row`)는 항상 같으므로, 헷갈리지 않게 하나는 지워주는 것이 코드를 더 깔끔하게 만듭니다.

```cpp
#include <vector>

using namespace std;

// 1. 매개변수에 const와 참조자(&)를 사용하여 성능과 안전성을 높입니다.
vector<vector<int>> solution(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    
    int arr1Row = arr1.size();
    int arr1Col = arr1[0].size();
    int arr2Col = arr2[0].size(); // arr2Row는 사용하지 않으므로 제거했습니다.
    
    // 2. 정답을 담을 2차원 벡터의 크기를 미리 할당하고, 모든 값을 0으로 초기화합니다.
    // 구조: vector<vector<int>> 이름(행의 개수, vector<int>(열의 개수, 초기값));
    vector<vector<int>> answer(arr1Row, vector<int>(arr2Col, 0));
    
    for (int i = 0; i < arr1Row; ++i) {
        for (int j = 0; j < arr2Col; ++j) {
            for(int k = 0; k < arr1Col; ++k) {
                // 3. answer가 이미 0으로 채워져 있으므로, 값을 바로 누적해서 더해줍니다.
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}
```

*/