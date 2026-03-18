// BFS

#include <string>
#include <vector>
#include <queue> // BFS를 위한 큐 라이브러리 포함

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    // 큐 생성: <현재까지의 합계, 다음 숫자의 인덱스>를 묶어서 저장합니다.
    queue<pair<int, int>> q;
    
    // 초기 상태: 합계는 0, 인덱스는 0번부터 시작
    q.push({0, 0}); 

    // 큐가 빌 때까지(모든 경우의 수를 다 확인할 때까지) 반복
    while (!q.empty()) {
        // 큐의 맨 앞에 있는 데이터를 꺼냅니다.
        int current_sum = q.front().first;
        int index = q.front().second;
        q.pop();

        // 1. 종료 조건: 배열의 모든 숫자를 다 사용한 경우
        if (index == numbers.size()) {
            // 최종 합계가 타겟 넘버와 같다면 정답 카운트 증가
            if (current_sum == target) {
                answer++;
            }
        } 
        // 2. 탐색 진행: 아직 사용할 숫자가 남은 경우
        else {
            // 현재 숫자를 더한 새로운 합계와 다음 인덱스를 큐에 삽입
            q.push({current_sum + numbers[index], index + 1});
            
            // 현재 숫자를 뺀 새로운 합계와 다음 인덱스를 큐에 삽입
            q.push({current_sum - numbers[index], index + 1});
        }
    }

    return answer;
}