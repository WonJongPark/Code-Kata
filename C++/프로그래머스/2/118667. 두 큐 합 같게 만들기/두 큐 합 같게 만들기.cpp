#include <string>
#include <vector>
#include <queue>

using namespace std;

#define dl long long

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    dl total = 0;
    
    dl sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    
    for (int num : queue1) {
        total += num;
        sum1 += num;
        q1.push(num);
    }
    
    for (int num : queue2) {
        total += num;
        sum2 += num;
        q2.push(num);
    }
    
    if (total % 2 != 0) return -1;
    
    while (answer < queue1.size() * 4) {
        if (sum1 > sum2) {
            int q1Front = q1.front();
            sum1 -= q1Front;
            sum2 += q1Front;
            q2.push(q1Front);
            q1.pop();
            answer++;
        }
        else if (sum1 < sum2) {
            int q2Front = q2.front();
            sum1 += q2Front;
            sum2 -= q2Front;
            q1.push(q2Front);
            q2.pop();
            answer++;
        }
        else if (sum1 == sum2) {
            return answer;
        }
    }
    
    
    return -1;
}