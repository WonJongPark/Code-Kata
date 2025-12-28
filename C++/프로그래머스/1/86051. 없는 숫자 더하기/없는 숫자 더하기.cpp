#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    for(int i = 0; i < 10; ++i) {
        answer += i;
    }
    
    for(const int& val : numbers) {
        answer -= val;
    }
    
    
    return answer;
}