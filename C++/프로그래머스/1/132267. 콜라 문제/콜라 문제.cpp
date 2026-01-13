#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int totalCola = 0;
    int giveCola = a;
    int takeCola = b;
    int currentCola = n;
    
    while(currentCola >= giveCola) {
        int receivenCola = (currentCola / giveCola) * takeCola;
        totalCola += receivenCola;
        currentCola = receivenCola + currentCola % giveCola;
    }
    
    
    return totalCola;
}