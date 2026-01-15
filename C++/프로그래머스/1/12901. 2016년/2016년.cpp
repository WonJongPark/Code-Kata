#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    map<int, int> calender =
    {{1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    int days = 0;
    
    for(size_t i = 1; i < a; ++i) {
        days += calender[i];
    }
    days += b;
    
    switch (days % 7) {
        case 0:
            answer = "THU";
            break;
            
        case 1:
            answer = "FRI";
            break;
                
        case 2:
            answer = "SAT";
            break;
            
        case 3:
            answer = "SUN";
            break;
            
        case 4:
            answer = "MON";
            break;
            
        case 5:
            answer = "TUE";
            break;
            
        case 6:
            answer = "WED";
            break;
            
        default:
            break;
    }
    
    
    return answer;
}