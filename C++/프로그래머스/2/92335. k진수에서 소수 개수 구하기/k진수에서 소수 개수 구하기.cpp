#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convertToBaseK(int number, int k) {
    if (number == 0) return "0";
    
    string result = "";
    
    
    while (number > 0) {
        result += to_string(number % k);
        number /= k;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

bool isPrime(long long n) {
    if (n <= 1) return false;
    
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string digit = convertToBaseK(n, k);
    string temp = "";
    
    for (char c : digit) {
        if (c == '0') {
            if (!temp.empty()) {
                long long num = stoll(temp);
                if (isPrime(num)) {
                    answer++;
                }
                temp = "";
            }
        }
        else {
            temp += c;
        }
    }
    
    if (!temp.empty()) {
        long long num = stoll(temp);
        if (isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}