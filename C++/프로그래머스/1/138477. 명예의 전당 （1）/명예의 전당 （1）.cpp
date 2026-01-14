#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> HOF;
    HOF.reserve(k);
    
    // k일까지는 전부 명예의 전당
    for(size_t i = 0; i < k && i < score.size(); ++i) {
        HOF.push_back(score[i]);
        auto it = min_element(HOF.begin(), HOF.end());
        answer.push_back(*it);
    }
    
    // k일 이후에는 비교 필요
    for(size_t i = k; i < score.size(); ++i) {
        auto it = min_element(HOF.begin(), HOF.end());
        if(score[i] > *it) {
            *it = score[i];
            answer.push_back(*min_element(HOF.begin(), HOF.end()));
        }
        else {
            answer.push_back(*it);
        }
    }
    
    return answer;
}