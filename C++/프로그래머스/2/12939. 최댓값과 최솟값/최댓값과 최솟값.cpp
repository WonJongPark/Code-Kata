#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    int minNum, maxNum;
    
    stringstream ss(s);
    
    vector<int> nums;
    string num;
    
    while(ss >> num) {
        nums.push_back(stoi(num));
    }
    
    minNum = nums[0];
    maxNum = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        minNum = min(minNum, nums[i]);
        maxNum = max(maxNum, nums[i]);
    }
    
    return to_string(minNum) + " " + to_string(maxNum);
}