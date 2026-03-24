#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> rightToppings;
    unordered_set<int> leftToppings;
    
    for (int i = 0; i < topping.size(); ++i) {
        rightToppings[topping[i]]++;
    }
    
    for (int i = 0; i < topping.size(); ++i) {
        leftToppings.insert(topping[i]);
        rightToppings[topping[i]]--;
        
        if (rightToppings[topping[i]] == 0) {
            rightToppings.erase(topping[i]);
        }
        
        if (leftToppings.size() == rightToppings.size()) {
            answer++;
        }
    }
    
    
    return answer;
}