#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<int, int> Xcount;
    map<int, int> Ycount;
    map<int, int> minCount;
    
    for(size_t i = 0; i < 10; ++i) {
        Xcount[i] = 0;
        Ycount[i] = 0;
        minCount[i] = 0;
    }
    
    for(char c : X) {
        Xcount[c - '0']++;
    } 
    
    for(char c : Y) {
        Ycount[c - '0']++;
    }
    
    for(int i = 9; i >= 0; --i) {
        minCount[i] = min(Xcount[i], Ycount[i]);
        for(size_t j = 0; j < minCount[i]; ++j) {
            answer += to_string(i);
        }
    }
    
    if(answer == "") return "-1";
    
    size_t i = 1;
    for(; i < 10; ++i) {
        if(minCount[i] != 0){
            break;
        }
    }
    if(i == 10) return "0";
    
    return answer;
}