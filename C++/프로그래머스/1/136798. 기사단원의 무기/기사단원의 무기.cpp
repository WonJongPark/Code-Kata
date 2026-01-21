// 챗봇의 개선사항 + 주석 추가
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    // 1. 약수의 개수를 저장할 배열(벡터) 선언
    // 인덱스를 1부터 N까지 편하게 쓰기 위해 크기를 N + 1로 잡는다.
    // 모든 값을 0으로 초기화.
    vector<int> divCount(number + 1, 0);

    // 2. 알고리즘 핵심: 배수를 이용한 카운팅
    for (int i = 1; i <= number; ++i) {
        // j는 i의 배수 (i, 2i, 3i ... N까지)
        for (int j = i; j <= number; j += i) {
            divCount[j]++; // j는 i를 약수로 가지므로 카운트 증가
        }
    }

    // [철의 무게 계산하기]
    // 0번 인덱스는 건너뛰고 1번부터 number까지 확인합니다.
    for (int i = 1; i <= number; ++i) {
        if (divCount[i] > limit) {
            answer += power;
        } else {
            answer += divCount[i];
        }
    }

    return answer;
}