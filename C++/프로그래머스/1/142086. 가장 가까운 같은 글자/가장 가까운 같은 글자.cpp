#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> recentIndex;
    
    for(size_t i = 0; i < s.size(); ++i) {
        if(recentIndex.find(s[i]) == recentIndex.end()) {
            answer.push_back(-1);
            recentIndex.insert({s[i], i});
        }
        else {
            answer.push_back(i - recentIndex[s[i]]);
            recentIndex[s[i]] = i;
        }
    }
    
    
    return answer;
}