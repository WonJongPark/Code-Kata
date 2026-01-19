#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if(num % 2 == 0 || num % 3 == 0) return false;
    
    for(int i = 5; i * i <= num; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for(size_t i = 0; i < nums.size() - 2; ++i) {
        for(size_t j = i + 1; j < nums.size() - 1; ++j){
            for(size_t k = j + 1; k < nums.size(); ++k){
                if(isPrime(nums[i] + nums[j] + nums[k])){
                    answer++;
                }
            }
        }
    }

    return answer;
}