#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.reserve(numbers.size());
    answer.assign(numbers.size(), -1);
    
    stack<int> index;
    
    for (int i = 0; i < numbers.size(); ++i) {
        while (!index.empty() && numbers[index.top()] < numbers[i]) {
            answer[index.top()] = numbers[i];
            index.pop();
        }
        
        index.push(i);
    }
    
    return answer;
}