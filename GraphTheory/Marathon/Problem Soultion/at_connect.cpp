#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 55;
char grp[N][N];
bool vis[N][N];
int n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > n or j > n or vis[i][j] == true or grp[i][j] == '1') {
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
    int r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grp[i][j];
        }
    }
 
    memset(vis, false, sizeof(vis));
    dfs (r1, c1);

    if (vis[r2][c2]) {
        cout << 0 << "\n";
        return;
    }

    vector<pair<int,int>> start, finish;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) {
                start.push_back({i, j});
            }
        }
    }


    memset(vis, false, sizeof(vis));
    dfs (r2, c2);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) {
                finish.push_back({i, j});
            }
        }
    }

    //now check for all possible pair and find the minimum cost
    int ans = 1e15;

    for (int i = 0; i < start.size(); i++) {
        auto [x, y] = start[i];
        for (int j = 0; j < finish.size(); j++) {
            auto [a, b] = finish[j];
            ans = min (ans, (x - a) * (x - a) + (y - b) * (y - b));
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

/*
key observation is : n is too low
-> find out the node which can be visited from source
-> if destination is visited, no need to create a new tunnel, cost is 0
-> if destination is not visited, find out the nodes which can be visited from destination node
-> the idea is simple, we will create a tunnel between two nodes where one is visited from source and another is visted from destination
*/