//complexity: O(V + E), for every vertices, we need to traverse through every possible adjacent node
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N];
vector<bool> vis(N,false);

void dfs(int u){   
    vis[u] = true;
    for(auto v : grp[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    int n,  e;   cin >> n >> e;
    
    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs(1);

// if there is a node  present that is not visited after traversing through dfs, it means that connected 
//component is more than one hence it is a disconnected graph
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "Disconnected graph\n";
        return 0;
        }
    }
    cout << "Connected graph\n";

    return 0;
}