#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    
    
    int gcdA = arrayA[0];
    for (int i = 1; i < arrayA.size(); ++i) {
        gcdA = gcd(gcdA, arrayA[i]);
    }
    
    int gcdB = arrayB[0];
    for (int i = 1; i < arrayB.size(); ++i) {
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    bool isValidA = true;
    bool isValidB = true;
    
    for (const int num : arrayB) {
        if (num % gcdA == 0) {
            isValidA = false;
            break;
        }
    }
    
    for (const int num : arrayA) {
        if (num % gcdB == 0) {
            isValidB = false;
            break;
        }
    }
    
    if (isValidA) {
        answer = max(answer, gcdA);
    }
    
    if (isValidB) {
        answer = max(answer, gcdB);
    }
    
    
    
    return answer;
}