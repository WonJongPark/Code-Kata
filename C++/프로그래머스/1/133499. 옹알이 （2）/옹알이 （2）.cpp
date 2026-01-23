// 챗봇의 최적화 코드
#include <string>
#include <vector>
#include <string_view>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    // 1. 발음 가능한 단어들을 배열(또는 벡터)로 관리합니다.
    // 데이터와 로직을 분리하여 확장성이 매우 좋습니다.
    const string_view valids[] = {"aya", "ye", "woo", "ma"};

    for (string_view sv : babbling) {
        // 직전 발음의 인덱스를 저장 (-1: 없음, 0:aya, 1:ye ...)
        // 문자열을 저장하는 것보다 정수(int) 비교가 훨씬 빠릅니다.
        int last_idx = -1; 
        bool is_possible = true;

        while (!sv.empty()) {
            bool matched = false;

            // 2. 4개의 발음 패턴을 순회하며 확인
            for (int i = 0; i < 4; ++i) {
                string_view target = valids[i];
                size_t len = target.size();

                // 길이 체크 & 내용 비교
                if (sv.size() >= len && sv.substr(0, len) == target) {
                    
                    // 3. 연속 발음 금지 조건 체크
                    if (last_idx == i) {
                        is_possible = false;
                        break; 
                    }

                    // 4. 발음 성공: 앞부분 자르기 (O(1) 속도)
                    sv.remove_prefix(len);
                    last_idx = i; // 현재 발음 인덱스 기록
                    matched = true;
                    break; // 매칭되었으므로 내부 for문 탈출 -> while문 처음으로
                }
            }

            // 이번 턴에 4개 중 아무것도 매칭되지 않았거나, 연속 발음 규칙을 어겼다면 실패
            if (!matched || !is_possible) {
                is_possible = false;
                break;
            }
        }

        if (is_possible) answer++;
    }

    return answer;
}

/* 이 코드가 "최적"인 이유
1. 데이터 주도 (Data-Driven):
    - if-else 도배 대신 valids 배열을 사용했습니다.
      만약 "chu"라는 옹알이가 추가된다면, valids 배열에 한 줄만 추가하면 됩니다. 코드를 뜯어고칠 필요가 없죠.

2. std::string_view의 완벽한 활용:
    - 매개변수 복사가 전혀 일어나지 않습니다.
    - remove_prefix를 사용하여 메모리 할당 없이 포인터 이동만으로 문자열을 자릅니다.

3. 빠른 비교 (last_idx):
    - 이전 발음을 문자열("aya")로 저장하는 대신, 인덱스(0)로 저장했습니다. 컴퓨터에게 문자열 비교보다 정수 비교가 훨씬 가볍고 빠릅니다.
    
4.안전성:
    - sv.size() >= len 조건을 명시하여 인덱스 범위를 벗어나는 잠재적인 오류를 방지했습니다.
*/