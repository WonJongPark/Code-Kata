#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int r1 = 0, r2 = 0;
    int g = 0, l = 0;
    
    if(n == m) {
        answer.push_back(n);
        answer.push_back(m);
        return answer;
    }
    else if(n > m) {
        r1 = n;
        r2 = m;
    }
    else {
        r1 = m;
        r2 = n;
    }
    
    
    while(true) {
        int tmp = 0;
        if(r1 % r2 == 0) {
            g = r2;
            answer.push_back(g);
            break;
        }
        else {
            tmp = r1 % r2;
            r1 = r2;
            r2 = tmp;
        }
    }
    l = (n * m) / g;
    answer.push_back(l);
    
    
    return answer;
}