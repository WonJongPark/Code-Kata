#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for(auto it = phone_number.rbegin() + 4; it != phone_number.rend(); ++it) {
        *it = '*';
    }
    answer = phone_number;
    
    return answer;
}