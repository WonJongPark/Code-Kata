#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    long long count[2001] = {0};
    
    for (int i = 0; i < weights.size(); ++i) {
        count[weights[i]]++;
    }
    
    for (int i = 100; i <= 1000; ++i) {
        if (count[i] == 0) continue;
        
        answer += static_cast<long long>(count[i]) * (count[i] - 1) / 2;
        
        if (i % 2 == 0) {
            answer += count[i] * count[i * 3 / 2];
        }
        
        if (i % 3 == 0) {
            answer += count[i] * count[i * 4 / 3];
        }
        
        answer += count[i] * count[i * 2];
    }
    
    return answer;
}
