#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, tc = 1; 

    while (cin >> n >> m) {

    vector<bool> good (10, true), vis (n, false);
    vector<int> par (n, 0), digit (n, 0);

    for (int i = 1; i <= m; i++) {
        int d; cin >> d;
        good[d] = false;
    }

    queue<int> q;
    
    for (int d = 1; d < 10; d++) {
        int x = d % n;

        if (good[d] and !vis[x]) {
            par[x] = -1;
            digit[x] = d;
            vis[x] = true;
            q.push(d);
        }
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (int d = 0; d < 10; d++) {

            int next_x = (x * 10 + d) % n;

            if (good[d] and !vis[next_x]) {
                vis[next_x] = true;
                par[next_x] = x;
                digit[next_x] = d;
                q.push(next_x);                
            }

        }
    }

    cout << "Case " << tc++ << ": "; 

    if (vis[0]) {
        vector<int> path;

        int cur = 0;

        while (cur != -1) {
            path.push_back(digit[cur]);
            cur = par [cur];
        }

        reverse(path.begin(), path.end());

        for (auto d : path) cout << d; cout << "\n";


    } else {
        cout << -1 << "\n";
    }
   
    }

return 0;
}