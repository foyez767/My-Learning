#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char grp[N][N], prevStep[N][N];
bool vis[N][N];
int n, m;
pair<int, int> start, finish;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir [] = {'D', 'U', 'R', 'L'};

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > n or j > m or vis[i][j] == true or grp[i][j] == '#') {
        return false;
    }
    return true;
}

void bfs () {
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];

            if (isValid(xx, yy)) {
                vis[xx][yy] = true;
                q.push({xx, yy});
                prevStep[xx][yy] = k;
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grp[i][j];
            vis[i][j] = false;

            if (grp[i][j] == 'A') {
                start = {i, j};
            } else if (grp[i][j] == 'B') {
                finish = {i, j};
            }
        }
    }

    bfs ();

    if (vis[finish.first][finish.second]) {
        vector<int> ans;

        while (finish != start) {
            int k = prevStep[finish.first][finish.second];

            ans.push_back(k);

            finish = {finish.first - dx[k], finish.second - dy[k]};
        }

        reverse(ans.begin(), ans.end());

        cout << "YES\n";

        cout << ans.size() << "\n";

        for (auto a : ans) cout << dir[a]; cout << "\n";


    } else {
        cout << "NO\n";
    }

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