#include<bits/stdc++.h>
using namespace std;

int main(){

    int xr = 0, n = 32;

    for (int i = 1; i <= n; i += 2) {
        xr ^= i;
        cout << i << ": " << xr << endl;
    }

return 0;
}