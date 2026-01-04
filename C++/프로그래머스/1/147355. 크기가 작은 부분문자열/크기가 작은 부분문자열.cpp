#include <string>
#include <string_view>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int length = p.length();
    
    string_view sv = t;
    
    for (size_t i = 0; i <= t.length() - length; ++i) {
        string_view window = sv.substr(i, length);
        if (window <= p) {
            answer++;
        }
    }
    
    return answer;
}