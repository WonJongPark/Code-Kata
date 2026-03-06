#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> addResults;
    int n = elements.size();
    
    for (int subLength = 1; subLength <= n; ++subLength) {
        for (int i = 0; i < n; ++i) {
            int addResult = 0;
            
            for (int j = i; j < i + subLength; ++j) {
                addResult += elements[j % n];
            }
            addResults.insert(addResult);
        }
    }
    return addResults.size();
}