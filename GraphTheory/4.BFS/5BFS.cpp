//***graph is connected
//complexity: O(V + E)
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N];
vector<bool> vis (N,false);

int main(){
    int n, e;   cin >> n >> e;
    int u, v;

    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    //bfs
    queue<int> q;

    q.push(1);      //traversing start from 1(let)
    vis[1] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : grp[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }


    return 0;
}