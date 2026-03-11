#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr1Row = arr1.size();
    int arr1Col = arr1[0].size();
    int arr2Row = arr2.size();
    int arr2Col = arr2[0].size();
    
    for (int i = 0; i < arr1Row; ++i) {
        vector<int> tempRow;
        
        for (int j = 0; j < arr2Col; ++j) {
            int result = 0;
            for(int k = 0; k < arr1Col; ++k) {
                result += arr1[i][k] * arr2[k][j];
            }
            tempRow.push_back(result);
        }
        
        answer.push_back(tempRow);
    }
    
    
    
    
    return answer;
}