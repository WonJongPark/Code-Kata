#include <string>
#include <vector>
#include <queue>

using namespace std;

struct task {
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> prio_queue;
    queue<task> normal_queue;
    
    for (int i = 0; i < priorities.size(); ++i) {
        prio_queue.push(priorities[i]);
        task tmpTask;
        tmpTask.priority = priorities[i];
        tmpTask.idx = i;
        normal_queue.push(tmpTask);
    }
    
    while (!normal_queue.empty()) {
        if (normal_queue.front().priority == prio_queue.top()) {
            if (normal_queue.front().idx == location) {
                answer++;
                break;
            }
            else {
                answer++;
                normal_queue.pop();
                prio_queue.pop();
            }
        }
        else {
            task tmpTask;
            tmpTask.priority = normal_queue.front().priority;
            tmpTask.idx = normal_queue.front().idx;
            normal_queue.pop();
            normal_queue.push(tmpTask);
        }
    }
    
    
    return answer;
}