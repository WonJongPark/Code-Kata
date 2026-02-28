#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int boxCount = 0;
    
    unordered_map<int, int> countMap;
    for(int i = 0; i < tangerine.size(); ++i) {
        countMap[tangerine[i]]++; 
    }
    
    vector<int> counts;
    for(auto const& pair: countMap) {
        counts.push_back(pair.second);
    }
    
    sort(counts.begin(), counts.end(), greater<int>());
    
    for(int i = 0; i < counts.size(); ++i) {
        k -= counts[i];
        boxCount++;
        
        if(k <= 0) {
            break;
        }
    }
    
    return boxCount;
}