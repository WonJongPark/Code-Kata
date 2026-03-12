#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int discountDays = discount.size();
    
    for (int i = 0; i <= discountDays - 10; ++i) {
        bool bCanRegisterDay = true;
        vector<int> tempNumber = number;
        
        for (int j = 0; j < want.size(); ++j) {
            
            bool bIsInDiscount = false;
            for(int k = i; k < i + 10; ++k) {
                if (want[j] == discount[k]) {
                    tempNumber[j]--;
                    bIsInDiscount = true;
                }
            }
            
            if (!bIsInDiscount) {
                bCanRegisterDay = false;
                break;
            }
        }
        
        bool bCanBuyAll = true;
        for (int l = 0; l < tempNumber.size(); ++l) {
            if (tempNumber[l] != 0) {
                bCanBuyAll = false;
                break;
            }
        }
        
        if (bCanRegisterDay && bCanBuyAll) {
            answer++;
        }
    }
    
    return answer;
}