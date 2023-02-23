//complexity : O(V + E)
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],indeg(N,0);
vector<bool> vis(N,false);

int main(){
    int n, e;   cin >> n >> e;
    int u, v;

    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);    //u->v
        indeg[v]++;
    }

    vector<int> ans,zin;

//separate node that has indegree 0
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            zin.push_back(i);
            vis[i] = true;
        }
    }

    while(ans.size() < n){
        if(zin.empty()){
            cout << "Impossible\n";
            return 0;
        }
        int cur = zin.back();
        zin.pop_back();
        ans.push_back(cur);

        for(auto v : grp[cur]){
            indeg[v]--;
            if(!vis[v] and indeg[v] == 0){
                zin.push_back(v);
                vis[v] = true;
            }
        }
    }

    for(auto x : ans) cout << x << " "; cout << endl;

    return 0;
}