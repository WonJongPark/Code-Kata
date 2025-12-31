#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length() != 4 && s.length() != 6) {
        return false;
    }
    for(auto it = s.begin(); it != s.end(); ++it) {
        if(*it < 48 || *it > 57) {
            answer = false;
            break;
        }
    }
    
    return answer;
}