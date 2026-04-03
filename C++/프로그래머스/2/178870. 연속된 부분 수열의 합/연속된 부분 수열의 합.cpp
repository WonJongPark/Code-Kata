#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left = 0, right = 0;
    int sum = sequence[0];
    
    int minLen = 2000000;
    vector<int> answer(2, 0);
    
    while (right < sequence.size()) {
        if (sum == k) {
            if (right - left < minLen) {
                answer[0] = left;
                answer[1] = right;
                
                minLen = right - left;
                
            }
            
            sum -= sequence[left];
            left++;
        }
        else if (sum < k) {
            right++;
            if(right < sequence.size()) {
                 sum += sequence[right];
            }
        }
        else if (sum > k) {
            sum -= sequence[left];
            left++;
        }
    }
    
    return answer;
}