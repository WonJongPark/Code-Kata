#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    tmp.reserve(array.size());
    
    for(size_t i = 0; i < commands.size(); ++i) {
        tmp = array;
        sort(tmp.begin() + commands[i][0] - 1, tmp.begin() + commands[i][1]);
        answer.push_back(tmp[commands[i][0] - 1 + commands[i][2] - 1]);
    }
    
    
    
    return answer;
}