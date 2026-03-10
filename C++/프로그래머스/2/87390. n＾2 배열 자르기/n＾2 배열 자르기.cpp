#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> arr;
    
    for(long long i = left; i <= right; ++i) {
        long long row = i / n;
        long long col = i % n;
        
        int value = max(row, col) + 1;
        arr.push_back(value);
    }
    
    return arr;
}