#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> box;
    box.reserve(m);
    box.assign(m, 0);
    
    sort(score.begin(), score.end(), greater<int>());
    for(size_t i = 0; i < score.size() / m; i++) {
        for(size_t j = 0; j < box.size(); j++){
            box[j] = score[i*m + j];
        }
        
        int minCost = *min_element(box.begin(), box.end());
        answer += m * minCost;
    }
    
    
    
    return answer;
}