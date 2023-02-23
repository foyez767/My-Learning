// complexity : O(V*V)
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],indeg(N,0);
bool vis[N];

int main(){
    int n, e;   cin >> n >> e;
    int u, v;

    for(int i = 1; i <= n; i++){    //u -> v
        cin >> u >> v;          //before v,we need to complete task number u // after u , we can do v
        indeg[v]++;
        grp[u].push_back(v);
    }

    vector<int> ans;

    while(ans.size() < n){
        int cur = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i] and indeg[i] == 0){
                cur = i;
                break;
            }
        }

        if(cur == 0){
            cout << "Impossible\n";
            return 0;
        }
        vis[cur] = true;
        ans.push_back(cur);

        for(auto v : grp[cur]){
            indeg[v]--;
        }
    }

    for(auto x : ans) cout << x << " ";  cout << endl;


    return 0;
}