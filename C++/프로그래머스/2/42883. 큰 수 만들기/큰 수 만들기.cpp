#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.length(); ++i) {
        while (!answer.empty() && k > 0 && answer.back() < number[i]) {
            answer.pop_back();
            k--;
        }
        
        answer.push_back(number[i]);
    }
    
    if (k > 0) {
        answer = answer.substr(0, answer.length() - k);
    }
    
    return answer;
}
