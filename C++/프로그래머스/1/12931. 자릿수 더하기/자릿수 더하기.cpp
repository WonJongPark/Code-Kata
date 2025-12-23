#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string num = to_string(n);
    for(int i = 0; i < num.length(); ++i) {
        answer += (num[i] - '0');
    }

    return answer;
}