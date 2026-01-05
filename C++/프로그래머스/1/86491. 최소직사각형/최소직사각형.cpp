#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int tmp = 0;
    
    
    for (size_t i = 0; i < sizes.size(); ++i) {
        if(sizes[i][0] < sizes[i][1]) {
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    
    int width = sizes[0][0], height = sizes[0][1];
    
    for(size_t i = 1; i < sizes.size(); ++i) {
        if(width < sizes[i][0]) {
            width = sizes[i][0];
        }
        if(height < sizes[i][1]) {
            height = sizes[i][1];
        }
    }
    
    answer = width * height;
    
    
    
    return answer;
}