#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int index_1 = 0, index_2 = 0;
    if(s.length() % 2 == 1) {
        index_1 = s.length() / 2;
        answer += s[index_1];
    }
    else {
        index_2 = s.length() / 2;
        index_1 = index_2 - 1;
        answer += s[index_1];
        answer += s[index_2];
    }
    
    return answer;
}