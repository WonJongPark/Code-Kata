using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long fee = 0;
    for(int i = 1; i <= count; ++i) {
        fee += price * i;
    }
    
    answer = (long long)money - fee;
    if(answer < 0) {
        answer *= -1;
    }
    else {
        return 0;
    }

    return answer;
}