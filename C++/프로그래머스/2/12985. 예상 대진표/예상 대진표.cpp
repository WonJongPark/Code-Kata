#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int maxRound = static_cast<int>(std::log2(n));

    for(int i = 1; i <= maxRound; ++i) {
        if(a % 2 == 0) {
            a = a / 2;
        }
        else {
            a = a / 2 + 1;
        }
        
        if(b % 2 == 0) {
            b = b / 2;
        }
        else {
            b = b / 2 + 1;
        }
        
        if(a == b) {
            return i;
        }
    }

    return answer;
}