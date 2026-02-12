#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int convertCount = 0, zeroCount = 0;
    
    while(s != "1") {
        int length = 0;
        
        for (char c : s) {
            if(c == '0') {
                zeroCount++;
            }
            else if(c == '1') {
                length++;
            }
        }
        
        s = "";
        while(length > 0) {
            s += to_string(length % 2);
            length /= 2;
        }
        
        reverse(s.begin(), s.end());
        
        convertCount++;
    }
    return {convertCount, zeroCount};
}