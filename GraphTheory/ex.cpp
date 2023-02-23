#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N];
int dep[N];
int node,maxi = 0;

void dfs1(int u, int p){
    dep[u] = dep[p] + 1;

    if(dep[u] > maxi){
        maxi = dep[u];
        node = u;
    }

    for(auto v : grp[u]){
        if(v != p){
            dfs1(v, u);
        }
    }
}

void dfs2(int u , int p){
    dep[u] = dep[p] + 1;
    maxi = max(maxi, dep[u] - 1);

    for(auto v : grp[u]){
        if(v != p){
            dfs2(v, u);
        }
    }
}

int main(){
    int n;  cin >> n;

    for(int i = 1; i <= n -1 ; i++){
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs1(1, 0);

    dfs2(node,0);

    cout << maxi << "\n";

return 0;
}