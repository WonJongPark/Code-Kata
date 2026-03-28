#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_string(const string& s1, const string& s2) {
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_numbers;
    for (int num : numbers) {
        str_numbers.push_back(to_string(num));
    }
    
    sort(str_numbers.begin(), str_numbers.end(), compare_string);
    
    if(str_numbers[0] == "0") return "0";
    
    for (const string& s : str_numbers) {
        answer += s;
    }
    
    return answer;
}

