// finding depth of all node in a tree
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grp[N];
int dep[N];

void dfs(int u, int p){
    dep[u] = dep[p] + 1;    // depth of child = depth of parent + 1

    for(auto v : grp[u]){
        if(v != p){
            dfs(v, u);       // for v, parent is u now
        }
    }
}

int main(){
    int n;      cin >> n;   // n = no of node; edge = n - 1 will be given as input

    int u, v;
    for(int i = 1; i <= n-1; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs(1, 0);  // let initailly parent is 0

    for(int i = 1; i <= n; i++) cout << dep[i] << " "; cout << endl;

    return 0;
}