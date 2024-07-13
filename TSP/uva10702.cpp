#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int memo[N][1005], profit[N][N], c, s, e, t;
bool endPoint[N];

int rec (int i, int d) {
    if (d == 0) return 0;
    if(memo[i][d] != -1) return memo[i][d];

    int ans = -1e9;

    if (d == 1) {
        for (int j = 0; j <= c; j++) {
            if(endPoint[j]) {       // a path will be valid if it start from any node but ends at given ending node
                ans = max (ans, profit[i][j]);
            }         
        }
        return memo[i][d] = ans;
    }

//travels ith node to every other node
    for (int j = 1; j <= c; j++) {
        ans = max (ans, rec (j, d - 1) + profit[i][j]);
    }

    return memo[i][d] = ans;
}

int main(){

    while (cin >> c >> s >> e >> t) {
        if (c == 0 and s == 0 and e == 0 and t == 0) {
            break;
        }

        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> profit[i][j];
            }
        }

        memset(memo, -1, sizeof(memo));
        memset(endPoint, false, sizeof(endPoint));

        for (int i = 1; i <= e; i++) {
            int x; cin >> x;
            endPoint[x] = true;
        }

        cout << rec (s, t) << "\n";

        memset(profit, 0, sizeof(profit));

    }

return 0;
}