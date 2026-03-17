#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_dungeons = 0;
bool visited[8] = {false};

void visit (int k, const vector<vector<int>>& dungeons, int count) {
    max_dungeons = max(max_dungeons, count);
    
    for (int i = 0; i < dungeons.size(); ++i) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            
            visit(k - dungeons[i][1], dungeons, count + 1);
            
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visit(k, dungeons, 0);
    
    return max_dungeons;
}