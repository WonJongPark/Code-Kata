#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    
    if (num == 2) return true;
    
    if (num % 2 == 0) return false;
    
    for (int i = 3; i * i <= num; ++i) {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

void makeCombinations(const string& currentNum, const string& numbers, vector<bool>& isUsed, unordered_set<int>& numSet) {
    if (!currentNum.empty()) {
        numSet.insert(stoi(currentNum));
    }
    
    
    
    for (int i = 0; i < numbers.size(); ++i) {
        if (isUsed[i]) continue;
        
        isUsed[i] = true;
        
        makeCombinations(currentNum + numbers[i], numbers, isUsed, numSet);
        
        isUsed[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<bool> isUsed(numbers.size(), false);
    
    unordered_set<int> numSet;
    
    makeCombinations("", numbers, isUsed, numSet);
    
    for (int num : numSet) {
        if (isPrime(num)) answer++;
    }
    
    return answer;
}