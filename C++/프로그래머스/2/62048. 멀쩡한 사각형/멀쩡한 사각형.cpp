#include <numeric>

using namespace std;

#define dl long long

dl solution(int w,int h) {
    dl GCD = gcd(w, h);
    
    dl DisableBoxCount = w + h - GCD;
    
    
    
    return static_cast<dl>(w) * static_cast<dl>(h) - DisableBoxCount;
}