#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto it = s.begin(); it != s.end(); ++it) {
        if(*it == ' ') {
            *it = ' ';
            continue;
        }        
        
        if ((*it) + n < 91) {
            *it += n;
        }
        else if (((*it) + n) > 90 && *it < 91) {
            *it = *it - 26 + n;
        }
        
        if((*it) + n < 123 && *it > 96) {
            *it += n;
        }
        else if((*it) + n > 122 && *it > 96) {
            *it = *it - 26 + n;
        }
    }
    
    answer = s;
    
    
    
    return answer;
}