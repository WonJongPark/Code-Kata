#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    if(x == y) return 0;
    
    vector<int> dp;
    dp.assign(y + 1, y + 1);
    dp[x] = 0;
    
    for (int i = x + 1; i <= y; ++i) {
        if (i - n >= x && dp[i - n] != y + 1) {
            dp[i] = min(dp[i], dp[i - n] + 1);
        }
        
        if (i % 2 == 0 && i / 2 >= x && dp[i / 2] != y + 1) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        
        if (i % 3 == 0 && i / 3 >= x && dp[i / 3] != y + 1) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    
    return (dp[y] == y + 1) ? -1 : dp[y];
}