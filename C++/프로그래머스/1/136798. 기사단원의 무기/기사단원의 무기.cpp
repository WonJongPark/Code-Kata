#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> divCount(number + 1, 0);
    
    for(size_t i = 1; i <= number; ++i) {
        for(size_t j = i; j <= number; j += i) {
            divCount[j]++;
        }
    }
    
    for(auto it = divCount.begin(); it != divCount.end(); ++it) {
        if(*it > limit) {
            answer += power;
            continue;
        }
        
        answer += *it;
    }
    
    return answer;
}