#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> arr(rows, vector<int>(columns, 0));
    int num = 1;
    for (int i = 0; i < arr.size(); ++i) {
        for(int j = 0; j < arr[i].size(); ++j) {
            arr[i][j] = num++;
        }
    }
    
    for (int i = 0; i < queries.size(); ++i) {
        for (int j = 0; j < queries[i].size(); ++j) {
            queries[i][j]--;
        }
    }
    
    for (int q = 0; q < queries.size(); ++q) {
        int x1 = queries[q][0];
        int y1 = queries[q][1];
        int x2 = queries[q][2];
        int y2 = queries[q][3];
        
        int temp = arr[x1][y1];
        int min_val = temp;
        
        for (int i = x1; i < x2; ++i) {
            arr[i][y1] = arr[i + 1][y1];
            min_val = min(min_val, arr[i][y1]);
        }
        
        for (int j = y1; j < y2; ++j) {
            arr[x2][j] = arr[x2][j + 1];
            min_val = min(min_val, arr[x2][j]);
        }
        
        for (int i = x2; i > x1; --i) {
            arr[i][y2] = arr[i - 1][y2];
            min_val = min(min_val, arr[i][y2]);
        }
        
        for (int j = y2; j > y1 + 1; --j) {
            arr[x1][j] = arr[x1][j - 1];
            min_val = min(min_val, arr[x1][j]);
        }
        
        arr[x1][y1 + 1] = temp;
        
        answer.push_back(min_val);
    }
    
    
    return answer;
}