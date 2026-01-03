#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int j = 0;
    
    for(size_t i = 0; i < s.size(); ++i) {
        if(j == 0 || j % 2 == 0) {
            if(s[i] >= 97 && s[i] <= 122) {
                s[i] -= 32;
            }
            j++;
        }
        else {
            if(s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
            j++;
        }
        
        if(s[i] == ' ') {
            j = 0;
        }
    }
    answer = s;
    
    
    return answer;
}