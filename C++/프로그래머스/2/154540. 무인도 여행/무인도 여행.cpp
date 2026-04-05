#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(vector<string>& maps, int x, int y) {
    if((x >= maps.size()) || x < 0 || (y >= maps[0].size()) || y < 0 || maps[x][y] == 'X') {
        return 0;
    }
    
    int food = maps[x][y] - '0';
    
    maps[x][y] = 'X';
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        food += dfs(maps, nx, ny);
    }
    
    return food;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); ++i) {
        for(int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] != 'X') {
                answer.push_back(dfs(maps, i, j));
            }
        }
    }
    
    if (answer.empty()) return { -1 };
    
    
    sort(answer.begin(), answer.end());
    
    
    
    return answer;
}