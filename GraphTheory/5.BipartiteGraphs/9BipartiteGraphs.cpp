//check a graph is bipartite or not
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],col(N,0);
vector<bool> vis(N,false);

bool ok = true;

void dfs(int u){
    vis[u] = true;

    for(auto v : grp[u]){
        if(!vis[v]){
            col[v] = !col[u];   
            dfs(v);
        }else{
            if(col[u] == col[v]){
                ok = false;
            }
        }
    }
}

int main(){
    int n, e;   cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    //for connected graph, just call dfs() function once
    //for disconnected graph ,we need to check every possible connected component
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    if(ok) cout << "Bipartite graph\n";
    else cout << "Not a bipartite graph\n";

    return 0;
}