#include <string>
#include <vector>

using namespace std;

string vowels = "AEIOU";

void dfs(string currentWord, const string& targetWord, int& count, bool& isFound) {
    if (isFound) return;
    
    if (currentWord != "") count++;
    
    if (currentWord == targetWord) {
        isFound = true;
        return;
    }
    
    if (currentWord.length() == 5) return;
    
    
    
    for (char c : vowels) {
        dfs(currentWord + c, targetWord, count, isFound);
    }
}

int solution(string word) {
    bool isFound = false;
    int count = 0;
    
    dfs("", word, count, isFound);
    return count;
}