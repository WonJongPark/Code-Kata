#include <string>
#include <vector>
#include <string_view>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // privacies의 날짜 + 약관 보관 기간 >= 오늘 날짜 -> 파기
    map<char, int> term;
    const int termIndex = 11;
    
    string_view sv = today;
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    
    int client_year = 0, client_month = 0, client_day = 0;
    char which_term = '\0';
    
    for(const string& s : terms) {
        string_view sv = s;
        sv.remove_prefix(2);
        term[s[0]] = stoi(string(sv.substr(0)));
        
        
    }
    
    for(int i = 0; i < privacies.size(); ++i) {
        sv = privacies[i];
        client_year = stoi(privacies[i].substr(0, 4));
        client_month = stoi(privacies[i].substr(5, 2));
        client_day = stoi(privacies[i].substr(8, 2));
        which_term = privacies[i][termIndex];
        
        client_month += term[which_term];
        if(client_month > 12) {
            if(client_month % 12 == 0) {
                client_year += client_month / 12 - 1;
                client_month = 12;
            } else {
                client_year += client_month / 12;
                client_month = client_month % 12;
            }
        }
        
        if(client_year < today_year) {
            answer.push_back(i + 1);
        }
        else if(client_year == today_year) {
            if(client_month < today_month) {
                answer.push_back(i + 1);
            }
            else if(client_month == today_month) {
                if(client_day <= today_day) {
                    answer.push_back(i + 1);
                }
            }
        }
        
    }
    
    return answer;
}