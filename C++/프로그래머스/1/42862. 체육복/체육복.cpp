#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> isLost(n + 2, false);
    vector<bool> canReserve(n + 2, false);
    
    for(int l : lost) isLost[l] = true;
    for(int r : reserve) canReserve[r] = true;
    
    for(int i = 1; i <= n; ++i) {
        if(isLost[i] && canReserve[i]) {
            isLost[i] = false;
            canReserve[i] = false;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if(isLost[i]) {
            if(canReserve[i - 1]) {
                isLost[i] = false;
                canReserve[i - 1] = false;
            }
            else if(canReserve[i + 1]) {
                isLost[i] = false;
                canReserve[i + 1] = false;
            }
        }
    }
    
    for(size_t i = 1; i <= n; ++i) {
        if(!isLost[i]) {
            answer++;
        }
    }
    
    return answer;
}