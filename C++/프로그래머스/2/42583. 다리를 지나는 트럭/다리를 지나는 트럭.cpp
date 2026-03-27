#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int current_weight = 0;
    queue<int> bridge;
    
    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }
    
    int i = 0;
    
    while (i < truck_weights.size()) {
        time++;
        
        current_weight -= bridge.front();
        bridge.pop();
        
        if (current_weight + truck_weights[i] <= weight) {
            bridge.push(truck_weights[i]);
            current_weight += truck_weights[i];
            i++;
        }
        else {
            bridge.push(0);
        }
    }
    
    time += bridge_length;
    
    return time;
}