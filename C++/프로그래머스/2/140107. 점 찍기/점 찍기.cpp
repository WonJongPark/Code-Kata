#include <string>
#include <vector>

using namespace std;

#define dl long long

dl solution(int k, int d) {
    dl answer = 0;
    
    dl y = k * (d / k);
    
    
    for (dl x = 0; x <= d; x += k) {
        dl squareX = x * x;
        dl squareY = y * y;
        
        while (squareX + squareY > (dl)d * d) {
            y = y - k;
            squareY = y * y;
        }
        
        answer += y / k + 1;
    }
    
    
    return answer;
}