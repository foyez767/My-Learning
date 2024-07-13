#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 25;
char grp [N][N];
bool vis [N][N];
int h, w, ans;
pair<int,int> start;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > h or j > w or grp[i][j] == '#' or vis[i][j] == true) {
        return false;
    }
return true;
}

void dfs (int i, int j) {
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];

        if (isValid(x, y)) {
            ans++;
            dfs (x, y);
        }
    }
}

void Reset (int h, int w) {
    ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            grp[i][j] = '.';
            vis[i][j] = false;
        }
    }
}

void solve(){
    cin >> w >> h;

    Reset (h, w);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grp[i][j];

            if (grp[i][j] == '@') {
                start = {i, j};
            }
        }
    }    

    dfs (start.first, start.second);

    cout << (ans + 1) << "\n";
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}