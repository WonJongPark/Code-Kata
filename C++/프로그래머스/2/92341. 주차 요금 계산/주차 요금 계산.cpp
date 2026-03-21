#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2)) * 60;
    
    int minutes = stoi(time.substr(3, 2));
    
    return hours + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime;
    map<string, int> totalTime;
    
    for (const string& record : records) {
        stringstream ss(record);
        string timeStr, carNum, status;
        
        ss >> timeStr >> carNum >> status;
        
        int currentMinutes = timeToMinutes(timeStr);
        
        if (status == "IN") {
            inTime[carNum] = currentMinutes;
        }
        else if (status == "OUT") {
            int parkedTime = currentMinutes - inTime[carNum];
            
            totalTime[carNum] += parkedTime;
            
            inTime.erase(carNum);
        }
    }
    
    for (const auto& pair : inTime) {
        string carNum = pair.first;
        int in_time = pair.second;
        
        int remainTime = timeToMinutes("23:59") - in_time;
        totalTime[carNum] += remainTime;
    }
    
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    vector<int> totalFees;
    for (const auto& pair : totalTime) {
        int totalFee = 0;
        int excessTime = pair.second - baseTime;
        
        if (excessTime > 0) {
            int tmpTime = (excessTime % unitTime == 0) ? (excessTime / unitTime) : (excessTime / unitTime + 1);
            totalFee = baseFee + tmpTime * unitFee;
        }
        else {
            totalFee = baseFee;
        }
        
        totalFees.push_back(totalFee);
    }
    
    return totalFees;
}