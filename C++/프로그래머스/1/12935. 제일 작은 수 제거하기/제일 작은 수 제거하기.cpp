#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tmp = arr;
    if(arr.size() == 1 || arr.empty()) {
        answer.push_back(-1);
        return answer;
    }
    sort(tmp.begin(), tmp.end());
    arr.erase(remove(arr.begin(), arr.end(), tmp[0]), arr.end());
    answer = arr;
    
    
    return answer;
}