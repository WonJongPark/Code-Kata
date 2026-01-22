// 챗봇의 개선사항

#include <string>
#include <vector>
#include <algorithm> // find 함수 등을 위해 사용 가능하지만, 여기선 기본 배열로 최적화

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // 1. 순위 정보를 담은 배열 (인덱스가 맞춘 개수, 값은 순위)
    // 0개 맞춤 -> 6등, 1개 -> 6등, 2개 -> 5등 ... 6개 -> 1등
    int rankMap[] = {6, 6, 5, 4, 3, 2, 1};

    int zeroCount = 0;
    int winCount = 0;

    // 2. 당첨 번호 확인을 빠르게 하기 위한 배열 (로또 번호는 1~45)
    bool isWinNum[46] = {false};
    for (int num : win_nums) {
        isWinNum[num] = true;
    }

    // 3. 로또 번호 확인
    for (int num : lottos) {
        if (num == 0) {
            zeroCount++;
        } else if (isWinNum[num]) {
            winCount++;
        }
    }

    // 4. 결과 계산 (최고: 맞춘 것 + 0의 개수, 최저: 이미 맞춘 것)
    // 배열을 이용해 순위를 바로 가져옵니다.
    int maxRank = rankMap[winCount + zeroCount];
    int minRank = rankMap[winCount];

    return {maxRank, minRank};
}

/*
 코드 설명 및 구현 지침위 코드가 왜 더 효율적이고 깔끔한지 단계별로 설명해 드릴게요.
 
1. 순위 계산 로직 변경 (switch $\rightarrow$ 배열)
기존 코드에서는 switch 문을 사용해 모든 경우(6, 5, 4...)를 일일이 적어주었습니다.
    - 개선: rankMap이라는 배열을 만들었습니다.
    - 원리: rankMap[맞춘개수]를 호출하면 바로 등수가 나옵니다.
        - 예: 6개를 맞췄다면 rankMap[6]의 값인 1을 가져옵니다.
        - 예: 1개를 맞췄다면 rankMap[1]의 값인 6을 가져옵니다.
    - 이렇게 하면 긴 switch 문을 단 한 줄로 줄일 수 있습니다.
    
2. 비교 로직 최적화 (이중 for문 $\rightarrow$ 단일 for문)
기존 코드에서는 lottos 하나를 꺼낼 때마다 win_nums 전체를 다시 훑어보는 방식(이중 루프)을 사용했습니다.
    - 개선: isWinNum이라는 체크리스트(배열)를 먼저 만듭니다.
    - 원리:
         1. win_nums를 한 번 훑어서 당첨 번호 위치를 true로 바꿉니다.
         2. 그다음 내 로또 번호를 확인할 때는 if (isWinNum[num])으로 즉시 당첨 여부를 알 수 있습니다.
    - 이렇게 하면 데이터가 아무리 많아져도 훨씬 빠르게 동작합니다.
    
3. 결과 반환 간소화
    - vector<int> answer를 선언하고 값을 대입하는 대신, 마지막에 return {maxRank, minRank};와 같이 작성하면 코드가 더 직관적입니다.
*/