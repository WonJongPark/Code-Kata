#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    // 음식의 개수를 2로 나눠 몫만큼 넣고 나머지는 버림
    // food[1]부터 food[n]까지 2로나눈 몫만큼 문자열에 넣고 문자열에 0을추가
    // 다시 food[n]부터 food[1]까지 문자열에 추가
    for(size_t i = 1; i < food.size(); ++i) {
        for(size_t j = 0; j < food[i] / 2; ++j) {
            answer += i + '0';
        }
    }
    
    answer += '0';
    
    for(size_t i = food.size() - 1; i > 0; --i) {
        for(size_t j = 0; j < food[i] / 2; ++j) {
            answer += i + '0';
        }
    }
    
    return answer;  
}