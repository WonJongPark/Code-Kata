#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr;
    while(true){
        arr.push_back(n % 3);
        n /= 3;
        if(n == 0) {
            break;
        }
    }
    int i = 1;
    for(auto it = arr.rbegin(); it != arr.rend(); ++it) {
        answer += (*it) * i;
        i *= 3;
    }
    
    return answer;
}