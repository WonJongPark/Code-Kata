#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(const vector<int>& nums, int target, int idx, int currentSum) {
    if (idx == nums.size()) {
        if (currentSum == target) {
            answer++;
        }
        return;
    }
    dfs(nums, target, idx + 1, currentSum + nums[idx]);
    
    dfs(nums, target, idx + 1, currentSum - nums[idx]);
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    
    return answer;
}