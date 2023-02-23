#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],cnt(N,0);
vector<bool> vis(N,false);

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    queue<int> q;
    q.push(1), vis[1] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : grp[u]){
            if(!vis[v]){
                cnt[v] = cnt[u] + 1;
                q.push(v);
                vis[v] = true;
            }
        }
    }

    //for which we want to determine no of shortest path
    cin >> u;
    cout << "no of shortest path : " << cnt[u] << "\n";

    return 0;
}