#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N], par (N,0);
bool vis[N], ok = false;
int ed = 0,pr = 0;

void dfs(int u, int p){
    vis[u] = true;

    for(auto v : grp[u]){
        if(!vis[v]){
            par[v] = u;
            vis[v] = true;
            dfs(v, u);
        }else if(v != p){
            ok = true;
            ed = u;
            pr = v;
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

    dfs(1, 0);

    if(ok){
        cout << pr << " ";
        while(pr != ed){
            cout << par[pr] << " ";
            pr = par[pr];
        }
    }


return 0;
}