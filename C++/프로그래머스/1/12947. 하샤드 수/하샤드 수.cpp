#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int sum = 0;
    string s = to_string(x);
    for(auto it = s.begin(); it != s.end(); ++it) {
        sum += *it - '0';
    }
    
    if(x % sum == 0) {
        answer = true;
    }
    
    return answer;
}