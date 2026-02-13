#include <string>
#include <vector>

using namespace std;

vector<long long> fiboNum;

long long Fibo(int n) {
    if(n <= 1) {
        return n;
    }
    
    if(fiboNum[n] != -1) {
        return fiboNum[n];
    }
    
    fiboNum[n] = (Fibo(n - 1) + Fibo(n - 2)) % 1234567;
    
    return fiboNum[n];
}

int solution(int n) {
    fiboNum.assign(n + 1, -1);
    
    return Fibo(n);
}