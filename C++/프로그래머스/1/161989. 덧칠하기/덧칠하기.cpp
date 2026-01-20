#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int currentSection = section[0];
    
    for(size_t i = 0; i < section.size(); ++i) {
      if(section[i] >= currentSection) {
            currentSection = section[i] + m;
            answer++;
        }
        
    }
    
    return answer;
}