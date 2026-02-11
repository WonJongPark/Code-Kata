#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.length(); ++i) {
        // 문자열의 시작이거나 바로 앞 문자가 공백인 경우는
        // 단어의 시작이므로 대문자로
        if(i == 0 || s[i - 1] == ' ') {
            answer += toupper(s[i]);
        }
        else {
            // 그 외는 소문자로
            answer += tolower(s[i]);
        }
    }
    
    return answer;
}