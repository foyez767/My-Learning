#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1003, mod = 1e9 + 7;
char grid[N][N];
ll ways[N][N];

void solve(){
    memset(ways, 0, sizeof(ways));
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    ways[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == '*'){
                ways[i][j] = 0;
                continue;
            }
            ways[i][j] += (ways[i - 1][j] + ways[i][j - 1]) % mod;
        }
    }

    if(grid[1][1] == '*') cout << "0\n";
    else cout << (ways[n][n] % mod) << "\n";
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}