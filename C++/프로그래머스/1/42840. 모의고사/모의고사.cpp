#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> stu1 = {1, 2, 3, 4, 5};
    vector<int> stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> stu3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int count1 = 0, count2 = 0, count3 = 0;
    
    if(stu1[0] == answers[0])
        count1++;
    if(stu2[0] == answers[0])
        count2++;
    if(stu3[0] == answers[0])
        count3++;
    
    
    for(size_t i = 1; i < answers.size(); ++i) {
        if(stu1[i % stu1.size()] == answers[i])
            count1++;
        if(stu2[i % stu2.size()] == answers[i])
            count2++;
        if(stu3[i % stu3.size()] == answers[i])
            count3++;
    }
    
    int maxAnswer = max({count1, count2, count3});
    
    if(count1 == maxAnswer) answer.push_back(1);
    if(count2 == maxAnswer) answer.push_back(2);
    if(count3 == maxAnswer) answer.push_back(3);
    
    
    return answer;
}