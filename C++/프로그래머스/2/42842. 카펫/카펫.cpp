// 챗 봇의 조언

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1. 전체 격자의 개수 계산
    int total = brown + yellow;
    
    // 2. 세로(height)를 3부터 증가시키며 탐색
    // 세로가 가로보다 길어지면 반복을 멈춰도 됩니다 (height * height <= total 조건 이용)
    for (int height = 3; height * height <= total; height++) {
        
        // 3. 전체 개수가 세로 길이로 나누어떨어지는지 확인 (직사각형 조건)
        if (total % height == 0) {
            int width = total / height; // 가로 길이 계산
            
            // 4. 중앙의 노란색 격자 개수가 맞는지 검증
            // 가로와 세로에서 각각 양쪽 테두리(2)를 뺀 공간이 yellow와 같아야 함
            if ((width - 2) * (height - 2) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                break; // 정답을 찾았으므로 반복 종료
            }
        }
    }
    
    return answer;
}