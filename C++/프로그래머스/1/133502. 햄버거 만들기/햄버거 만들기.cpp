#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for(int n : ingredient) {
        stack.push_back(n);
        
        if(stack.size() >= 4){
            if(
                stack[stack.size() - 1] == 1 &&
                stack[stack.size() - 2] == 3 &&
                stack[stack.size() - 3] == 2 &&
                stack[stack.size() - 4] == 1
            ) {
                answer++;
                
                for(int i = 0; i < 4; i++)
                    stack.pop_back();
            }
        }
    }
    
    
    return answer;
}