#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N];
vector<bool> vis(N,false);
vector<int> dis(N,0);

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    int x, y;
    cin >> x >> y;      //shortest distance from x to y
    
    queue<int> q;
    q.push(x);      // let source is 1
    vis[x] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : grp[u]){
            if(!vis[v]){
                vis[v] = true;
                dis[v] = dis[u] + 1;    //parent distance from source + 1 = current node er distance from source
                q.push(v);
            }
        }
    }

    cout << dis[y] << "\n";
    
    return 0;
}