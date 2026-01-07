#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& s1, const string& s2) {
        if(s1[n] != s2[n]) {
            return s1[n] < s2[n];
        }
        
        return s1 < s2;
    });
    
    
    return strings;
}