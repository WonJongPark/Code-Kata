#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);
    int zeroCount = 0, winNumsCount = 0;
    
    for(int i = 0; i < lottos.size(); ++i) {
        if(lottos[i] == 0) {
            zeroCount++;
            continue;
        }
        
        for(int j = 0; j < win_nums.size(); ++j) {
            if(lottos[i] == win_nums[j]) {
                winNumsCount++;
            }
        }
    }
    
    answer[0] = zeroCount + winNumsCount;
    answer[1] = winNumsCount;
    
    for(int i = 0; i < 2; i++) {
        switch(answer[i]) {
            case 6:
                answer[i] = 1;
                break;
            case 5:
                answer[i] = 2;
                break;
            case 4:
                answer[i] = 3;
                break;
            case 3:
                answer[i] = 4;
                break;
            case 2:
                answer[i] = 5;
                break;
            default:
                answer[i] = 6;
                break;
        }
    }
    
    
    return answer;
}