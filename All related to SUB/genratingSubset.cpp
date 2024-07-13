//complexity : O(N * 2^N)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> vec(n, 0);

    for(auto &x : vec) cin >> x;

    //generating subset

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {   //if ith bit is on
                cout << vec[i] << " ";
            }
        }
        cout << "\n";
    }


return 0;
}