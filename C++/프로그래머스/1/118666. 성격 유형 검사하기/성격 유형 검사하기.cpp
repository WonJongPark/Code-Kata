#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<string, bool> isNegativeScore = {
        {"RT", false}, {"TR", true},
        {"CF", false}, {"FC", true},
        {"JM", false}, {"MJ", true},
        {"AN", false}, {"NA", true}
    };
    vector<int> choicesScore(9 ,0);
    for(int i = 1; i <= 7; ++i) {
        choicesScore[i] = 4 - i;
    }
    
    vector<int> score(4, 0);
    
    for(int i = 0; i < survey.size(); ++i) {
        if(survey[i] == "RT" || survey[i] == "TR") {
            isNegativeScore[survey[i]] ? score[0] -= choicesScore[choices[i]] : score[0] += choicesScore[choices[i]]; 
        }
        else if(survey[i] == "CF" || survey[i] == "FC") {
            isNegativeScore[survey[i]] ? score[1] -= choicesScore[choices[i]] : score[1] += choicesScore[choices[i]];
        }
        else if(survey[i] == "JM" || survey[i] == "MJ") {
            isNegativeScore[survey[i]] ? score[2] -= choicesScore[choices[i]] : score[2] += choicesScore[choices[i]];
        }
        else if(survey[i] == "AN" || survey[i] == "NA") {
            isNegativeScore[survey[i]] ? score[3] -= choicesScore[choices[i]] : score[3] += choicesScore[choices[i]];
        }
    }

    score[0] >= 0 ? answer += "R" : answer += "T";
    score[1] >= 0 ? answer += "C" : answer += "F";
    score[2] >= 0 ? answer += "J" : answer += "M";
    score[3] >= 0 ? answer += "A" : answer += "N";
    
    
    return answer;
}