#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isMinus = false;
    int ten = 1;
    
    if((*s.begin()) == '-') {
        isMinus = true;
    }
    
    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        if(*it == '-' || *it == '+'){
            break;
        }  
        answer += (*it - '0') * ten;
        ten *= 10;
    }
    if(isMinus == true) {
        answer *= -1;
    }
    
    
    return answer;
}