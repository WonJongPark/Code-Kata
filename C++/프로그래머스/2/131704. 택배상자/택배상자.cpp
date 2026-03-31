#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    
    vector<int> loaded;
    stack<int> tempBelt;
    
    int orderIdx = 0;
    
    for (int box = 1; box <= order.size(); ++box) {
        if (box == order[orderIdx]) {
            loaded.push_back(order[orderIdx]);
            orderIdx++;
        }
        else {
            tempBelt.push(box);
        }
        
        while (!tempBelt.empty() && tempBelt.top() == order[orderIdx]) {
            loaded.push_back(tempBelt.top());
            tempBelt.pop();
            orderIdx++;
        }
    }
    
    
    return loaded.size();
}