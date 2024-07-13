#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char grp[N][N];
bool vis[N][N];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > n or j > m or vis[i][j] == true or grp[i][j] == '#') {
        return false;
    }
    return true;
}

void dfs (int i, int j) {
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];

        if (isValid(x, y)) {
            dfs (x, y);
        }
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grp[i][j];
            vis[i][j] = false;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (isValid(i, j)) {
                ans ++;
                dfs (i, j);
            }
        }
    }

    cout << ans << "\n";

}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}