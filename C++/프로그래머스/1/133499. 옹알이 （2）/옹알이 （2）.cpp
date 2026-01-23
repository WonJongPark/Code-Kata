#include <string>
#include <string_view>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int pronounceCount = 0;
    vector<string> canPronounce = {"", "aya", "ye", "woo", "ma"};
    
    for(const string& word : babbling) {
        string_view sv = word;
        string_view lastPronounce = "";
        
        bool isPossible = true;
        
        while(!sv.empty()) {
            if(sv.substr(0, 3) == canPronounce[1]) {
                if(lastPronounce == canPronounce[1]) {
                    isPossible = false;
                    break;
                }
                sv.remove_prefix(3);
                lastPronounce = canPronounce[1];
            }
            else if(sv.substr(0, 2) == canPronounce[2]) {
                if(lastPronounce == canPronounce[2]) {
                    isPossible = false;
                    break;
                }
                sv.remove_prefix(2);
                lastPronounce = canPronounce[2];
            }
            else if(sv.substr(0, 3) == canPronounce[3]) {
                if(lastPronounce == canPronounce[3]) {
                    isPossible = false;
                    break;
                }
                sv.remove_prefix(3);
                lastPronounce = canPronounce[3];
            }
            else if(sv.substr(0, 2) == canPronounce[4]) {
                if(lastPronounce == canPronounce[4]) {
                    isPossible = false;
                    break;
                }
                sv.remove_prefix(2);
                lastPronounce = canPronounce[4];
            }
            else {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible) {
            pronounceCount++;
        }
    }
    
    
    return pronounceCount;
}