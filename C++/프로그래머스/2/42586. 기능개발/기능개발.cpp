#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;
    while (idx < progresses.size()) {
        for (int i = idx; i < progresses.size(); ++i) {
            progresses[i] += speeds[i];
        }
        
        int done = 0;
        if(progresses[idx] >= 100) {
            int currentIdx = idx;
            
            for (int i = currentIdx; i < progresses.size(); ++i) {
                
                if (progresses[i] >= 100) {
                    idx++;
                    done++;
                }
                else {
                    break;
                }
            }
        }
        
        if (done > 0) answer.push_back(done);
    }
    
    return answer;
}