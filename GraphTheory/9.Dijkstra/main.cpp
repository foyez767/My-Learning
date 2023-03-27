//dijkstra using set
//complexity: O(VlogV + E)
#include<bits/stdc++.h>
using namespace std;

const int N = 1000, inf = 1e9;
vector<int> grp[N], cost[N];

int main(){
    int n, e; cin >> n >> e;    //n = no of node, e = no of edge

    for(int i = 1; i <= e; i++){
        int u, v, w; cin >> u >> v >> w;
        grp[u].push_back(v);
        grp[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int src, target; cin >> src >> target;  //source and target

    vector<int> dis(N , inf);
    set<pair<int,int>> se;
    dis[src] = 0;           //initially distance of source from source is zero
    se.insert({0, src});    //in pair, second = node no, first = min distance from source till now

    while(!se.empty()){
        auto it = se.begin();
        int u = (*it).second;   
        se.erase(it);   //**

        for(int i = 0; i < grp[u].size(); i++){
            int v = grp[u][i];

            if(dis[u] + cost[u][i] < dis[v]){
                //if some value for a node is already present, we need to erase it before update 
                if(se.find({dis[v],v}) != se.end()){
                    se.erase({dis[v], v});
                }

                dis[v] = dis[u] + cost[u][i];
                se.insert({dis[v], v}); //**
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " "; cout << endl;


return 0;
}