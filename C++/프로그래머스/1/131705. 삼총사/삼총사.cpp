#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(size_t i = 0; i < number.size() - 2; ++i) {
        for(size_t j = i + 1; j < number.size() - 1; ++j) {
            for(size_t k = j + 1; k < number.size(); ++k) {
                if((number[i] + number[j] + number[k] == 0)) {
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}