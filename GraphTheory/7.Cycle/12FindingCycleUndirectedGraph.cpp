// if v is already visited but it is not the parent , means there must be a cycle
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],par(N,0);
bool vis[N], ok = false;

// p = parent of u
void dfs(int u,int p){
    vis[u] = true;

    for(auto v : grp[u]){
        if(!vis[v]){
            dfs(v, u);
        }else if(v != p){
            ok = true;
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

    dfs(1,0);
    
    if(ok) cout << "Yes ! cycleeee\n";
    else cout << "No cycle\n";


return 0;
}