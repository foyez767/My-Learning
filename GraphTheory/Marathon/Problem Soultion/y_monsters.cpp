#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005, inf = 1e9 + 7;
char grp[N][N];
bool vis_me[N][N], vis_mons[N][N];
int time_me[N][N], time_mons[N][N], n, m, prevStep[N][N];
pair<int,int> start;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir [] = {'D', 'U', 'R', 'L'};

bool isValid (int i, int j, int rank) {
    if (rank == 0) {
        if (i < 1 or j < 1 or i > n or j > m or vis_me[i][j] == true or grp[i][j] == '#' or grp[i][j] == 'M') {
            return false;
        }
        return true;

    } else if (rank == 1) {
        if (i < 1 or j < 1 or i > n or j > m or vis_mons[i][j] == true or grp[i][j] == '#') {
            return false;
        } 
        return true;
    } 
return true;
}

void bfs (queue<pair<int,int>> &q) {

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];

            if (isValid(x, y, 0)) {
                q.push({x, y});
                time_me[x][y] = 1 + time_me[i][j];
                vis_me[x][y] = true;
            }
        }

    }
}

void bfs2 (queue<pair<int,int>> &q) {

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];

            if (isValid(x, y, 1)) {
                q.push({x, y});
                time_mons[x][y] = min(time_mons[x][y], time_mons[i][j] + 1);
                vis_mons[x][y] = true;
            }
        }

    }
}

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > n or j > m or vis_me[i][j] == true or grp[i][j] == '#' or time_mons[i][j] <= time_me[i][j])
        return false;
return true;
}

void bfs3 (int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis_me[i][j] = false;
        }
    }
    
    queue<pair<int, int>> q;
    q.push(start);
    vis_me[start.first][start.second] = true;

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];

            if (isValid(x, y)) {
                q.push({x, y});
                vis_me[x][y] = true;
                prevStep[x][y] = k;
            }
        }
    }
}

void reset (int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis_me[i][j] = vis_mons[i][j] = false;
            time_me[i][j] = time_mons[i][j] = inf;
        }
    }
}

void solve(){
    cin >> n >> m;

    reset(n, m);

    queue<pair<int,int>> me, mons;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grp[i][j];

            if (grp[i][j] == 'A') {
                start = {i, j};
                vis_me[i][j] = true;
                time_me[i][j] = 0;
                me.push({i, j});
            } else if (grp[i][j] == 'M') {
                mons.push({i, j});
                vis_mons[i][j] = true;
                time_mons[i][j] = 0;
            } else {
                time_me[i][j] = inf;
                time_mons[i][j] = inf;
            }
        }
    }

    bfs (me);
    bfs2 (mons);

    bfs3(n, m);

//checking if any of the boarder cell can be visited
    int row [2] = {1, n}, col [2] = {1, m};
    bool psbl = false;
    pair<int, int> finish;

//first row , last row check
    for (int i = 0; i <= 1; i++)  {
        for (int j = 1; j <= m; j++) {
            if (vis_me[row[i]][j]) {
                psbl |= true;
                finish = {row[i], j};
            }
        }
    }
//first column and last column check
    for (int j = 0; j <= 1; j++) {
        for (int i = 1; i <= n; i++) {
            if (vis_me[i][col[j]]) {
                psbl |= true;
                finish = {i, col[j]};
            }
        }
    }

    //processing answer
    if (!psbl) {
        cout << "NO\n";
    } else {
        vector<int> steps;

        while (finish != start) {
            int k = prevStep[finish.first][finish.second];

            steps.push_back(k);

            finish = {finish.first - dx[k], finish.second - dy[k]};
        }

        reverse(steps.begin(), steps.end());

        cout << "YES\n";
        cout << steps.size() << "\n";
        for (auto k : steps) cout << dir[k] ; cout << "\n";

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