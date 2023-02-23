//initially for all node, color is 0(not visited)
//when we visit a node , color is 1(red) and it is active (recursion is not finished yet for that node)
//when recursion is finished for a particular node, we make it inactive/ color 2  (blue)
//in traversing process, if a node face an active / red node, then there is a cycle
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],col(N,0);
bool cycle = false;

void dfs(int u){
    col[u] = 1;
    for(auto v : grp[u]){
        if(col[v] == 0)
            dfs(v);
        else if(col[v] == 1)
            cycle = true;
    }
    col[u] = 2;
}

int main(){
    int n, e;   cin >> n >> e;
    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
    }
    
    //disconnected graph
    for(int i = 1; i <= n; i++){
        if(col[i] == 0){
            dfs(i);
        }
    }

    if(cycle){
        cout << "Cycle Present\n";
    }else cout << "NO cycle\n";

    return 0;
}