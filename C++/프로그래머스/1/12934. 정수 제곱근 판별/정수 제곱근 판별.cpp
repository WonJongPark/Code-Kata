#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long x = 1;
    for(x = 1; x <= n/x; x++) {
        if(n / x == x && n % x == 0) {
            answer = (x + 1) * (x + 1);
            return answer;
        }
    }
    
    answer = -1;
    return answer;
}