#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ToMinute(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    
    return hours * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int, int>> converted_time(book_time.size());
    
    for (int i = 0; i < book_time.size(); ++i) {
        converted_time[i].first = ToMinute(book_time[i][0]);
        converted_time[i].second = ToMinute(book_time[i][1]) + 10;
    }
    
    sort(converted_time.begin(), converted_time.end());
    
    vector<int> rooms;
    
    for (const pair<int, int>& time : converted_time) {
        
        bool isAssigned = false;
        for(int j = 0; j < rooms.size(); ++j) {
            if (rooms[j] <= time.first) {
                rooms[j] = time.second;
                isAssigned = true;
                break;
            }
        }
        
        if(!isAssigned) {
            rooms.push_back(time.second);
        }
    }
    
    return rooms.size();
}