// 챗봇이 제안한 코드 개선사항
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 1. 점수를 내림차순으로 정렬합니다. (큰 점수가 앞으로 오도록)
    sort(score.begin(), score.end(), greater<int>());
    
    // 2. 상자를 만들 수 있는 만큼만 반복합니다.
    // i는 각 상자에서 가장 낮은 점수를 가진 사과의 인덱스를 가리킵니다.
    // 예: m=3이면 인덱스 2, 5, 8... 순서로 접근
    for(int i = m - 1; i < score.size(); i += m) {
        // 해당 상자의 최저 점수(score[i]) * 상자에 담긴 사과 개수(m)
        answer += score[i] * m;
    }
    
    return answer;
}