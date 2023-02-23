//counting indegree and outdegree for a directed graph
#include<bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> grp[N],indeg(N,0),outdeg(N,0);

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }

    for(int i = 1; i <= n; i++){
        cout << "No of adjacent : " << grp[i].size() << "\n";
        cout << "Edges with : ";
        for(auto v : grp[i]) cout << v << " "; cout << "\n";
        cout << "Indeg : " << indeg[i] << "\n";
        cout << "Outdeg : " << outdeg[i] << "\n";
        cout << "###########\n";
    }


return 0;
}