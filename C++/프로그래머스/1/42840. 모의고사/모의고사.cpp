// 챗봇의 개선사항
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 수포자들의 찍기 패턴
    vector<int> stu1 = {1, 2, 3, 4, 5};
    vector<int> stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> stu3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int count1 = 0, count2 = 0, count3 = 0;
    
    // [개선 포인트] 0번 인덱스부터 끝까지 한 번에 반복합니다.
    // 이전 코드에서 0번을 따로 체크하던 중복을 제거했습니다.
    for(size_t i = 0; i < answers.size(); ++i) {
        if(stu1[i % stu1.size()] == answers[i]) count1++;
        if(stu2[i % stu2.size()] == answers[i]) count2++;
        if(stu3[i % stu3.size()] == answers[i]) count3++;
    } // 분모가 0만 아니면 되는데 분자가 0인게 0으로 나눈다고 착각함....
    
    // 가장 높은 점수 계산
    int maxAnswer = max({count1, count2, count3});
    
    // 가장 높은 점수를 받은 사람을 오름차순으로 추가
    if(count1 == maxAnswer) answer.push_back(1);
    if(count2 == maxAnswer) answer.push_back(2);
    if(count3 == maxAnswer) answer.push_back(3);
    
    return answer;
}