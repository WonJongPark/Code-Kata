#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char firstChar = '\0';
    int firstCharCount = 0, otherCharCount = 0;
    
    for(auto it = s.begin(); it != s.end(); ++it) {
        if(firstChar == '\0') {
            firstChar = *it;
            firstCharCount++;
        }
        else if(firstChar == *it) {
            firstCharCount++;
        }
        else if(firstChar != *it) {
            otherCharCount++;
        }
        
        if(firstCharCount == otherCharCount) {
            answer++;
            firstChar = '\0';
        }
        else if(firstCharCount != otherCharCount && (it + 1) == s.end()){
            answer++;
        }
    }
    
    return answer;
}