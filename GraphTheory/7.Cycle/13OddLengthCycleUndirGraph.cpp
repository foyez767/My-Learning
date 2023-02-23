//checking if an odd length cycle is present in an undirected graph
//**if bicoloring is possible, it means there is no odd length cycle, if bicoloring not possible , then there 
// is odd cycle present
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],col(N,0);
bool vis[N], ok = true;

void dfs(int u){
    vis[u] = true;

    for(auto v : grp[u]){
        if (!vis[v]){
            col[v] = !col[u];
            dfs(v);
        }else{
            if(col[u] == col[v]){
                ok =false;
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
    //for connected graph
    //dfs(starting point);
    
    //for disconnected graph
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    if(ok) cout << "No odd length cycle possible\n";
    else cout << "Yes, odd length cycle heree\n";

    return 0;
}