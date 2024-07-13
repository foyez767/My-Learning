#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 7, b = 9;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping : " << a << " " << b << "\n";

return 0;
}

/*
    x = a ^ b
    b = x ^ b // now b = a, why ? (a ^ b) ^ b = a
    a = x ^ a // now a = b, why ? (a ^ b) ^ a = b
*/