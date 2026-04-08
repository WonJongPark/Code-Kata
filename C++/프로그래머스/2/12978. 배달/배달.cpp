#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair <int, int>>> graph(N + 1);
    
    for (int i = 0; i < road.size(); ++i) {
        graph[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        graph[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    vector<int> dist(N + 1, 2000000);
    dist[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push( {0, 1} );
    
    while (!pq.empty()) {
        int currentTime = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        if (currentTime > dist[currentNode]) continue;
        
        for (int i = 0; i < graph[currentNode].size(); ++i) {
            int newTime = currentTime + graph[currentNode][i].second;
            
            if (newTime < dist[graph[currentNode][i].first]) {
                dist[graph[currentNode][i].first] = newTime;
                pq.push(make_pair(newTime, graph[currentNode][i].first));
            }
        }
    }
    
    for (int i = 1; i < dist.size(); ++i) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}