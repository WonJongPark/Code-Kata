#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    for(size_t i = 0; i < b; ++i) {
        for(size_t j = 0; j < a; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}