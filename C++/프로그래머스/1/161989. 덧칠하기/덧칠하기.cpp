#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    // 현재 롤러로 칠해져 있는 마지막 지점을 저장할 변수입니다.
    // 아직 아무것도 칠하지 않았으므로 0으로 초기화하거나, 
    // 첫 번째 섹션 처리 로직을 위해 아주 작은 수로 둡니다.
    int painted_until = 0; 
    
    for(size_t i = 0; i < section.size(); ++i) {
        // 현재 구역(section[i])이 칠해진 범위(painted_until)보다 크다면
        // 아직 칠해지지 않은 곳이라는 뜻입니다.
        if(section[i] >= painted_until) {
            
            // 칠하는 횟수 증가
            answer++;
            
            // 새로운 롤러질은 현재 구역(section[i])부터 시작해 m미터만큼 칠합니다.
            // 따라서 칠해진 범위는 section[i] + m 이 됩니다.
            painted_until = section[i] + m;
        }
    }
    
    return answer;
}