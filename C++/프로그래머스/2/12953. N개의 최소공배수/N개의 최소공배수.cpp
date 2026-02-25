#include <string>
#include <vector>

using namespace std;


long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long LCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    
   
    return (a / GCD(a, b)) * b;
}

int solution(vector<int> arr) {
    long long lastLCM = LCM(arr[0], arr[1]);
    
    for(int i = 2; i < arr.size(); ++i) {
        lastLCM = LCM(lastLCM, arr[i]);
    }
    
    return lastLCM;
}
