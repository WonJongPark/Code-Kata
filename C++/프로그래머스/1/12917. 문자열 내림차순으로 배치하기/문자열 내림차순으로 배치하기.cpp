#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), [](char a, char b) {
        return a > b;
    });
    answer = s;
    
    return answer;
}