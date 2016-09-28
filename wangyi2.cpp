#include <iostream>
using namespace std;

int main() {
     int N;
     cin >> N;
     int tail_0 = 0;
     int tail_1 = 0;
     int cur = N;
     while(((cur & 1) == 0) && (cur != 0)){
         tail_0++;
         cur >>= 1;
     }
     while((cur & 1)==1) {
         tail_1 ++;
         cur >>= 1;
     }
    int val2 = (N + (1 << (tail_1 - 1)) + (1 << tail_0) - 1);
    cout << val2 << endl;
    return 0;

}