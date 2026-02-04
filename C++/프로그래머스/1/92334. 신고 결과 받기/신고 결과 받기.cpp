#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    // 각 id별로 report 당한 횟수
    // 어떤 id를 누가 report 했는지
    unordered_map<string, int> reportCount;
    unordered_map<string, vector<string>> whoReport;
    unordered_map<string, int> mailCount;
    
    for(int i = 0; i < id_list.size(); ++i) {
        reportCount[id_list[i]] = 0;
        mailCount[id_list[i]] = 0;
    }
    
    for(int i = 0; i < report.size(); ++i) {
        int spaceIndex = report[i].find(' ');
        
        string reporter = report[i].substr(0, spaceIndex);
        string reportId = report[i].substr(spaceIndex + 1);
        
        auto it = find(whoReport[reportId].begin(), whoReport[reportId].end(), reporter);
        if(it == whoReport[reportId].end()) {
            whoReport[reportId].push_back(reporter);
            reportCount[reportId] += 1;
        }
    }
    
    // 
    
    
    for(const string& Id : id_list) {
        if(reportCount[Id] >= k) {
            for(const string& reporter : whoReport[Id]) {
                mailCount[reporter] += 1;
            }
        }
    }
    
    for(const string& Id : id_list) {
        answer.push_back(mailCount[Id]);
    }
    
    return answer;
}