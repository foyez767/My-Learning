#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e13;


void floyd_warshall (vector<vector<int>> &dis, int n) {

    for (int k = 1; k <= n; k++) {
        //let k is the middle element
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

}

int32_t main(){
    int n, e; cin >> n >> e;

    vector<vector<int>> dis (n + 1, vector<int> (n + 1, inf));

    for (int i = 1; i <= e; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
    }

    // //dis from [i to i] = 0
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    floyd_warshall(dis, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dis[i][j] << " "; 
        }
        cout << "\n";
    }

return 0;
}

/*
4 5
1 3 -2
3 4 2
4 2 -1
2 1 4
2 3 3



4 6
1 2 3
2 1 2
2 3 2
3 2 5
4 3 8
4 1 20

time complexity : O(N^3)
space complexity : O(N^2)
*/