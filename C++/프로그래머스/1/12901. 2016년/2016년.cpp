#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    const vector<int> daysByMonth = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const vector<string> daysName = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int days = 0;
    
    for(size_t i = 1; i < a; ++i) {
        days += daysByMonth[i];
    }
    days += b;
    
    answer = daysName[days % 7];
    
    
    return answer;
}