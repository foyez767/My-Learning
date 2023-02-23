//print a cycle //problem ache ,parent thik moto kaj korte parsi na
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],col(N,0),par(N,0);
bool cycle = false;
int x = 0;

void dfs(int u){
    col[u] = 1;

    for(auto v : grp[u]){
        if(col[v] == 0){
            par[v] = u;
            dfs(v);
        }
        else if(col[v] == 1){
            x = v;
            cycle = true;
        }
    }
    col[u] = 2;
}

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= n; i++){
        cin >> u >> v;
        grp[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(col[i] == 0){
            dfs(i);
        }
    }

    if(cycle){
        while(x != 1){
            cout << par[x] << " ";
            x = par[x];
        }
    }else {
        cout << "No cycle\n";
    }
    return 0;
}