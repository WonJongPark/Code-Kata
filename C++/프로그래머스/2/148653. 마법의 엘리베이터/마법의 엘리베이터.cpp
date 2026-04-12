#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        int num = storey % 10;
        
        if (num < 5) {
            answer += num;
        }
        else if (num > 5) {
            answer += (10 - num);
            storey += 10;
        }
        else {
            int nextNum = (storey / 10) % 10;
            if (nextNum >= 5) {
                storey += 10;
                answer += (10 - num);
            }
            else {
                answer += num;
            }
        }
        
        
        storey = storey / 10;
    }
    
    return answer;
}