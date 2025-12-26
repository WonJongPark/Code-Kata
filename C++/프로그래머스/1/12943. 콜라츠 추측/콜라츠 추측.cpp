#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long var = (long long )num;
    
    if(num == 1) {
        return 0;
    }
    
    while(true) {
        if(answer == 500) {
            answer = -1;
            break;
        }
        else if(var == 1) {
            break;
        }
        else if(var % 2 == 0) {
            var /= 2;
            answer++;
        }
        else if(var % 2 == 1) {
            var = (var * 3) + 1;
            answer++;
        }
        
    }
    
    return answer;
}