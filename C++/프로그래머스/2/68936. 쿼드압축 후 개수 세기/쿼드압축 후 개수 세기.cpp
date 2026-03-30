#include <string>
#include <vector>

using namespace std;

void compress(int row, int col, int size, const vector<vector<int>>& arr, vector<int>& answer) {
    bool isSame = true;
    
    for (int i = row; i < row + size; ++i) {
        for (int j = col; j < col + size; ++j) {
            if (arr[row][col] != arr[i][j]) {
                isSame = false;
                break;
            }
        }
        if(!isSame) break;
    }
    
    if (isSame) {
        answer[arr[row][col]]++;
        return;
    }
    
    int half = size / 2;
    compress(row, col, half, arr, answer);
    compress(row, col + half, half, arr, answer);
    compress(row + half, col, half, arr, answer);
    compress(row + half, col + half, half, arr, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    
    compress(0, 0, arr.size(), arr, answer);
    
    return answer;
}