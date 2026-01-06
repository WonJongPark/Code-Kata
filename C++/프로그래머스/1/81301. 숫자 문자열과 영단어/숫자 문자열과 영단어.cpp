#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string number = "";
    
    for(size_t i = 0; i < s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            number += s[i];
            continue;
        }
        
        switch(s[i]) {
            case 'e':
                number += '8';
                i += 4;
                break;
                
            case 'f':
                if(s[i + 1] == 'o') {
                    number += '4';
                }
                else if(s[i + 1] == 'i') {
                    number += '5';
                }
                i += 3;
                break;
                
            case 'n':
                number += '9';
                i += 3;
                break;
                
            case 'o':
                number += '1';
                i += 2;
                break;
                
            case 's':
                if(s[i + 1] == 'i') {
                    number += '6';
                    i += 2;
                }
                else if(s[i + 1] == 'e') {
                    number += '7';
                    i += 4;
                }
                break;
                
            case 't':
                if(s[i + 1] == 'w') {
                    number += '2';
                    i += 2;
                }
                else if(s[i + 1] == 'h') {
                    number += '3';
                    i += 4;
                }
                break;
                
            case 'z':
                number += '0';
                i += 3;
                break;
                
            default:
                break;      
        }
    }
    
    answer = stoi(number);
    return answer;
}