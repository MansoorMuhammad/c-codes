#include <iostream>
 #include <cmath>
 using namespace std;
 int main() {
    int bin, dec = 0, i = 0;
    cin >> bin;
    while(bin != 0) {
        int rem = bin % 10;
        dec += rem * pow(2, i);
        ++i;
        bin /= 10;
    }
        cout << dec;
    return 0;
}

