#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dfs(int current, const int ignore1, const int ignore2, vector<bool>& isVisited, const vector<vector<int>>& graph) {
    isVisited[current] = true;
    
    int count = 1;
    for (int i = 0; i < graph[current].size(); ++i) {
        int nextNode = graph[current][i];
        if (((current == ignore1) && (nextNode == ignore2)) || ((current == ignore2) && (nextNode == ignore1)))
            continue;
        
        if (isVisited[graph[current][i]])
            continue;
        
        count += dfs(graph[current][i], ignore1, ignore2, isVisited, graph);
    }
    
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < wires.size(); ++i) {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    int answer = 999999999;
    
    for (int i = 0; i < wires.size(); ++i) {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        
        vector<bool> isVisited(n + 1);
        
        int count = dfs(v1, v1, v2, isVisited, graph);
        int otherCount = n - count;
        answer = min(abs(count - otherCount), answer);
    }
    
    return answer;
}