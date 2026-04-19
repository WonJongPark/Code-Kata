#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
        if (a[col - 1] == b[col - 1]) {
            return a[0] > b[0];
        }
        
        return a[col - 1] < b[col - 1];
    });
    
    for (int i = row_begin - 1; i <= row_end - 1; ++i) {
        int current_S_i = 0;
        
        for (int j = 0; j < data[i].size(); ++j) {
            current_S_i += data[i][j] % (i + 1);
        }
        
        answer = answer ^ current_S_i;
    }
    
    return answer;
}