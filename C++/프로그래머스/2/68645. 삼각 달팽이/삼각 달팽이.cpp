#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int num = 1;
    int row = -1, col = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i % 3 == 0) {
                row++;
            } 
            else if (i % 3 == 1) {
                col++;
            }
            else if (i % 3 == 2) {
                row--;
                col--;
            }
            
            board[row][col] = num++;
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(board[i][j]);
        }
    }
    
    
    return answer;
}
