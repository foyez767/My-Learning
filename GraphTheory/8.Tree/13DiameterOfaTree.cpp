//dfs1 = finding largest distance from any node, this node is an endpoint of the diameter
//dfs2 = finding largest distance from the node for which in dfs1 we found longest distance
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int dep[N],ans,maxi = 0,node;
vector<int> grp[N];

void dfs1(int u , int p){
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

void dfs2(int u, int p){
    dep[u] = dep[p] + 1;
    ans = max(maxi, dep[u] - 1);    //in dfs1 ,we alreday add 1 in dep[u], now again we are adding 1 in dep[u]
                                // hence we are adding extra one, we need to subtract it
    for(auto v : grp[u]){
        if(v != p)
            dfs2(v, u);
    }
}

int main(){
    int n;  cin >> n;

    int u, v;
    for(int i = 1; i <= n-1; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(node,0);
    
    cout << ans << "\n";

    return 0;
}