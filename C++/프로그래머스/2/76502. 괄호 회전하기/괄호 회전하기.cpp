#include <string>
#include <string_view>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    string_view sv(s);
    
    int length = s.length();
    
    for (int i = 0; i < length; ++i) {
        stack<char> st;
        bool isValid = true;
        
        for (int j = 0; j < length; ++j) {
            char c = sv[(i + j) % length];
            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    isValid = false;
                    break;
                }
                
                char top = st.top();
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        
        if (isValid && st.empty()) {
            answer++;
        }
    }
    
    return answer;
}