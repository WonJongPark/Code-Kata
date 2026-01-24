// 챗봇의 최적화
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    // 0~9까지의 개수를 저장할 벡터 (map 대신 사용)
    // 인덱스 자체가 숫자를 의미하므로 접근 속도가 매우 빠름
    vector<int> countX(10, 0);
    vector<int> countY(10, 0);
    
    // X의 각 숫자 개수 세기
    for(char c : X) {
        countX[c - '0']++;
    }
    
    // Y의 각 숫자 개수 세기
    for(char c : Y) {
        countY[c - '0']++;
    }
    
    // 9부터 0까지 역순으로 순회 (가장 큰 수를 만들기 위함)
    for(int i = 9; i >= 0; i--) {
        // 두 문자열에 공통으로 나타난 횟수 중 작은 값만큼 추가
        int commonCount = min(countX[i], countY[i]);
        
        for(int j = 0; j < commonCount; j++) {
            // to_string(i) 대신 char 연산 사용
            answer += (i + '0');
        }
    }
    
    // 예외 처리
    if (answer == "") return "-1"; // 짝꿍이 없는 경우
    if (answer[0] == '0') return "0"; // 0만 공통인 경우 (예: "00" -> "0")
    
    return answer;
}

/*
1. 빈도수 배열 초기화 (countX, countY)
    - vector<int>(10, 0)을 사용하여 0으로 초기화된 크기 10의 배열을 만듭니다. map보다 메모리를 적게 쓰고 접근 속도가 빠릅니다.

2. 개수 세기
    - c - '0'을 통해 문자('0'~'9')를 정수(0~9) 인덱스로 변환하여 카운트합니다.

3. 큰 수부터 문자열 만들기
    - i를 9부터 0까지 줄여가며 반복합니다. 이렇게 하면 자동으로 가장 큰 수가 만들어지므로, 나중에 정렬할 필요가 없습니다.
    - min(countX[i], countY[i])를 통해 공통된 개수를 구하고, 그 횟수만큼 answer에 문자를 추가합니다.

4. 효율적인 예외 처리
    - answer가 비어있으면 짝꿍이 없으므로 "-1"입니다.
    - answer의 첫 글자가 '0'이라면, 내림차순으로 만들었기 때문에 그 뒤도 전부 '0'입니다. 
      따라서 그냥 "0"을 리턴합니다. (예: answer가 "000"인 경우 "0" 리턴).
*/