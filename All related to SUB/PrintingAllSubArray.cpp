//subarray is contigious
//no of subarray = n * (n + 1) / 2;
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> vec(n, 0);

    for(auto &x : vec) cin >> x;

    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            //subarray vec[l....r]
            for(int k = l; k <= r; k++) {
                cout << vec[k] << " ";
            }

            cout << "\n";
        }
    }

return 0;
}

//time complexity : O(N^3)