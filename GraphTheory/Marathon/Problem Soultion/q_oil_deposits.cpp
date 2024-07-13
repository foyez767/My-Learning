#include<bits/stdc++.h>
using namespace std;

const int N = 105;
char grp[N][N];
bool vis[N][N];
int n, m;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid (int i, int j) {
    if (i < 1 or j < 1 or i > n or j > m or grp[i][j] == '*' or vis[i][j] == true) {
        return false;
    } 
return true;
}

void dfs (int i, int j) {
    vis[i][j] = true;

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (isValid(x, y)) {
            dfs (x, y);
        }
    }
}

int main(){

    while (cin >> n >> m and (n != 0)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grp[i][j];
            }
        }

        int no_oil_depo = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (isValid(i, j)) {
                    no_oil_depo++;
                    dfs (i, j);
                }
            }
        }

        cout << no_oil_depo << "\n";

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                grp[i][j] = '.';
                vis[i][j] = false;
            }
        }
    }

return 0;
}