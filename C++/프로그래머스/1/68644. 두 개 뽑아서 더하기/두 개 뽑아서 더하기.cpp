#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    answer.reserve(n * (n - 1) / 2);
    
    for(size_t i = 0; i < n - 1; ++i) {
        for(size_t j = i + 1; j < n; j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());
    auto last = unique(answer.begin(), answer.end());
    answer.erase(last, answer.end());
    
    return answer;
}