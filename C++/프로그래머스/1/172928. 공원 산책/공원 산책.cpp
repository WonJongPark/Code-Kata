// 챗봇의 Best Practice
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();
    int W = park[0].length();
    int curY = 0, curX = 0; // Y는 행(세로), X는 열(가로)

    // 1. 시작 위치('S') 찾기
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (park[i][j] == 'S') {
                curY = i;
                curX = j;
                break;
            }
        }
    }

    // 2. 방향 정의 (N, S, W, E 에 따른 좌표 변화량)
    // N: 위(-1, 0), S: 아래(+1, 0), W: 왼쪽(0, -1), E: 오른쪽(0, +1)
    map<char, pair<int, int>> directions;
    directions['N'] = {-1, 0};
    directions['S'] = {1, 0};
    directions['W'] = {0, -1};
    directions['E'] = {0, 1};

    // 3. 명령 수행
    for (const string& route : routes) {
        char op = route[0];
        int n = route[2] - '0';

        int dy = directions[op].first;
        int dx = directions[op].second;

        int tempY = curY;
        int tempX = curX;
        bool canMove = true;

        // n칸 만큼 미리 가보면서 확인
        for (int i = 0; i < n; ++i) {
            tempY += dy;
            tempX += dx;

            // 공원 벗어나는지 확인 OR 장애물('X')인지 확인
            if (tempY < 0 || tempY >= H || tempX < 0 || tempX >= W || park[tempY][tempX] == 'X') {
                canMove = false;
                break;
            }
        }

        // 이동 가능하다면 실제 위치 업데이트
        if (canMove) {
            curY = tempY;
            curX = tempX;
        }
    }

    return {curY, curX};
}

/*
프로그래머스 '공원 산책' 문제를 스스로 해결하신 것 정말 축하해요! 🎉
작성하신 코드는 문제의 요구 사항을 정확하게 파악하고 있고, 경계값 체크나 장애물('X') 처리 로직도 꼼꼼하게 구현되어 있습니다. 정답을 맞히는 데에는 전혀 문제가 없는 코드입니다.

이제 이 코드를 **"현업 개발자가 선호하는 방식"**과 **"알고리즘 문제 풀이의 정석"**에 가깝게 다듬어 볼게요.

---

### 🔍 작성하신 코드의 개선 포인트

작성해주신 코드에서 개선하면 좋을 3가지 포인트를 짚어 드릴게요.

1. **메모리 효율성 (불필요한 배열 제거):**
    * 현재 `parkArr`라는 `bool` 타입의 2차원 벡터를 새로 만드셨어요.
    * 하지만 `park` 벡터 자체에 이미 'S', 'O', 'X' 정보가 들어있습니다. 굳이 `parkArr`를 따로 만들지 않고 `park[i][j]`를 직접 확인하면 메모리와 초기화 시간을 아낄 수 있어요.

2. **코드 중복 제거 (DRY 원칙):**
    * `switch` 문 안에서 E, W, S, N을 처리하는 로직이 거의 똑같습니다. (범위 체크 -> 장애물 체크 -> 이동).
    * 방향만 다르고 로직은 같으므로, 이를 하나의 로직으로 통합하면 코드가 훨씬 짧고 읽기 쉬워집니다.

3. **방향 벡터(Delta Array) 사용:**
    * 이동 문제(BFS, DFS, 시뮬레이션 등)에서는 `dx`, `dy` (또는 `dr`, `dc`)라고 부르는 방향 배열을 사용하는 것이 정석입니다. 이를 사용하면 `switch` 문을 없앨 수 있습니다.

---

### 💡 코드 구현 및 변경 사항 설명

**1. 시작 위치 찾기 단순화**
 * 작성하신 코드와 같지만, `park` 벡터를 직접 사용하여 `parkArr` 생성 과정을 생략했습니다.
 
**2. `map`과 방향 벡터 사용**
    * `switch` 문 대신 `map`을 사용하여 방향 문자('N', 'S' 등)를 좌표 변화량(`dy`, `dx`)으로 매핑했습니다.
        * 예: `'N'`이 들어오면 세로로 -1만큼(`dy`), 가로로 0만큼(`dx`) 이동합니다.
    * 이렇게 하면 4개의 케이스를 하나의 코드로 처리할 수 있습니다.

**3. 통합된 검증 로직**
    * `tempY`, `tempX` 변수를 사용해 **가상의 위치**로 한 칸씩 이동해 봅니다.
    * `if` 문 하나로 **"범위 벗어남"**과 **"장애물 만남"**을 동시에 체크합니다.
        * `park[tempY][tempX] == 'X'`를 직접 조회하므로 별도의 불리언 배열이 필요 없습니다.
    * 중간에 문제가 발견되면 `break` 하고, 문제가 없었을 때만(`if (canMove)`) 실제 위치(`curY`, `curX`)를 업데이트합니다.
*/