#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int j = 0, k = 0;
    
    for (const string& word : goal) {
        // &&는 앞의 조건이 거짓이면 뒤의 조건을 검사하지 않으므로 size체크를 먼저해야 인덱스가 범위를 벗어나는 일이 없다. 
        if (j < cards1.size() && word == cards1[j]) {
            j++;
            continue;
        }
        else if (k < cards2.size() && word == cards2[k]) {
            k++;
            continue;
        }
        else {
            return "No";
        }
    }
    
    return "Yes";
}