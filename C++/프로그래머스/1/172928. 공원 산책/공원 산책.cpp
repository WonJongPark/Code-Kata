#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<vector <bool>> parkArr(park.size(), vector<bool>(park[0].length(), true));
    int curPosX, curPosY;
    const int MAX_HEIGHT = park.size();
    const int MAX_WIDTH = park[0].length();

    
    for(int i = 0; i < park.size(); ++i) {
        for(int j = 0; j < park[i].length(); ++j) {
            if(park[i][j] == 'O')
                continue;
            
            if(park[i][j] == 'X') {
                parkArr[i][j] = false;
            }
            else if(park[i][j] == 'S') {
                curPosX = i;
                curPosY = j;
            }
        }
    }
    
    for(int i = 0; i < routes.size(); ++i) {
        char cDir;
        int moveN;
        cDir = routes[i][0];
        moveN = routes[i][2] - '0';
        
        switch (cDir) {
            case 'E':
                if(curPosY + moveN >= MAX_WIDTH) {
                    continue;
                }
                else {
                    bool canMove = true;
                    
                    for(int i = 1; i <= moveN; ++i) {
                        if(parkArr[curPosX][curPosY + i] == false){
                            canMove = false;
                        }
                    }
                    
                    if(canMove) {
                        curPosY += moveN;
                    }
                }
                break;
                
            case 'W':
                if(curPosY - moveN < 0) {
                    continue;
                }
                else {
                    bool canMove = true;
                    
                    for(int i = 1; i <= moveN; ++i) {
                        if(parkArr[curPosX][curPosY - i] == false){
                            canMove = false;
                        }
                    }
                    
                    if(canMove) {
                        curPosY -= moveN;
                    }
                }
                break;
                
            case 'S':
                if(curPosX + moveN >= MAX_HEIGHT) {
                    continue;
                }
                else {
                    bool canMove = true;
                    
                    for(int i = 1; i <= moveN; ++i) {
                        if(parkArr[curPosX + i][curPosY] == false){
                            canMove = false;
                        }
                    }
                    
                    if(canMove) {
                        curPosX += moveN;
                    }
                }
                break;
                
            case 'N':
                if(curPosX - moveN < 0) {
                    continue;
                }
                else {
                    bool canMove = true;
                    
                    for(int i = 1; i <= moveN; ++i) {
                        if(parkArr[curPosX - i][curPosY] == false){
                            canMove = false;
                        }
                    }
                    
                    if(canMove){
                        curPosX -= moveN;
                    }
                }
                break;
                
            default:
                break;
        }
    }
    
    
    return {curPosX, curPosY};
}