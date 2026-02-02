#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> rankByPlayer;
    map<int, string> playerByRank;
    
    for(int i = 0; i < players.size(); ++i) {
        rankByPlayer[players[i]] = i + 1;
        playerByRank[i + 1] = players[i];
    }
    
    for(size_t i = 0; i < callings.size(); ++i) {
        string curPlayer = callings[i];
        int curPlayerRank = rankByPlayer[callings[i]];
        string prevPlayer = playerByRank[curPlayerRank - 1];
        int prevPlayerRank = rankByPlayer[prevPlayer];
        
        rankByPlayer[curPlayer] -= 1;
        rankByPlayer[prevPlayer] += 1;
        playerByRank[curPlayerRank] = prevPlayer;
        playerByRank[prevPlayerRank] = curPlayer;
    }
    
    for(const auto& pair : playerByRank) {
        answer.push_back(pair.second);
    }
    
    return answer;
}