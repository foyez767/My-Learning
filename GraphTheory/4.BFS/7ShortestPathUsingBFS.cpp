#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N];
vector<bool> vis(N,false);
vector<int> par(N,0);  //stores parent node

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    int x, y;   cin >> x >> y;      //find the shortest path from x to y

    queue<int> q;
    q.push(x), vis[x] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : grp[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                par[v] = u;
            }
        }
    }

    //printing shortest path
    cout << y << " ";
    while(y != x){
        cout << par[y] << " ";
        y = par[y];
    }

   
    return 0;
}