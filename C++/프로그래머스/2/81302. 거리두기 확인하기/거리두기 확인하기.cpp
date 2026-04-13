#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r, c, dist;
};

int dr[] = {-1, 1, 0 ,0};
int dc[] = {0, 0, -1, 1};

bool CheckDistance(const vector<string>& place, int start_r, int start_c) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    queue<Point> q;
    
    q.push({start_r, start_c, 0});
    visited[start_r][start_c] = true;
    
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        
        if (curr.dist == 2) continue;
        
        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !visited[nr][nc]) {
                if (place[nr][nc] == 'P') {
                    return false;
                }
                else if (place[nr][nc] == 'O') {
                    q.push({nr, nc, curr.dist + 1});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (const vector<string>& place : places) {
        bool bIsSafe = true;
        
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (place[r][c] == 'P') {
                    if (!CheckDistance(place, r, c)) {
                        bIsSafe = false;
                        break;
                    }
                }
            }
        }
        
        if (bIsSafe) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    
    return answer;
}