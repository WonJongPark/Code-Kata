#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> fastestKeyCount;
    
    for(int i = 0; i < keymap.size(); ++i) {
        for(int j = 0; j < keymap[i].length(); ++j) {
            if(fastestKeyCount.find(keymap[i][j]) == fastestKeyCount.end()) {
                fastestKeyCount[keymap[i][j]] = j + 1;
                continue;
            }
            
            if(fastestKeyCount[keymap[i][j]] > j + 1) {
                fastestKeyCount[keymap[i][j]] = j + 1;
            }
        }
    }
    
   
    for(const string& s : targets) {
        int keyCount = 0;
        bool canMakeString = true;
        for(char c : s) {
            if(fastestKeyCount.find(c) == fastestKeyCount.end()){
                canMakeString = false;
                break;
            }
            keyCount += fastestKeyCount[c];
        }
        if(canMakeString){
            answer.push_back(keyCount);
        }
        else {
            answer.push_back(-1);
        }
        
    }
    
    return answer;
}