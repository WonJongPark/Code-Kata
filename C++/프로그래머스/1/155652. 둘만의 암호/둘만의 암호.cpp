#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    // skip에 있는 문자는 +1
    // s[i] = s[i] + index + (s[i] ~ (s[i] + index 사이의 skip 수))
    map<char, bool> skipChar;
    for(char c : skip) {
        skipChar[c] = true;
    }
    
    for(char c : s) {
        for(int i = 0; i < index; ++i) {
            c++;
            if(c > 'z') {
                c = 'a';
            }
            
            while(skipChar.find(c) != skipChar.end()){
                c++;
                if(c > 'z') {
                    c = 'a';
                }
            }
        }
        answer += c;
    }
    

    
    
    return answer;
}