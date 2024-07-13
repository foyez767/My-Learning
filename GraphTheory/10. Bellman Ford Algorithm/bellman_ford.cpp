#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e13;

void Bellman_Ford(int n, int src, vector<tuple<int,int,int>> &edges, vector<int> &distance) {
    distance[src] = 0;

    for (int i = 1; i < n; i++) {   // we need to do path relaxation maximum (n - 1) times where n is number of node

        for (auto [u, v, cst] : edges) {
            
            if (distance[u] < INF and distance[u] + cst < distance[v]) {
                distance[v] = distance[u] + cst;
            }
        }
    }

    // checking if there is any negative cycle 
   /*
    we obtain the criterion for presence of a cycle of negative weights reachable for source vertex  
    v : after (n-1)th  phase, if we run algorithm for one more phase, and it performs at least one more relaxation, 
    then the graph contains a negative weight cycle that is reachable from v; otherwise, such a cycle does not exist
   */

    for (auto [u, v, cst] : edges) {

        if (distance[u] < INF and distance[u] + cst < distance[v]) {
            cout << "Negative Cycle Detected\n";
            exit(0);        //program terminated
        }
    }
}

int32_t main(){

    int n, e, src; cin >> n >> e >> src;    //n = no of node, e = no of edge, src = source node 

    vector<tuple<int,int,int>> edges;

    for (int i = 1; i <= e; i++) {
        int u, v, cst; cin >> u >> v >> cst;
        edges.push_back({u, v, cst});
    }

    vector<int> distance (n + 1, INF);

    Bellman_Ford(n, src, edges, distance);

    for (int i = 1; i <= n; i++) {
        cout << distance[i] << " \n " [i == n];
    }


return 0;
}

/*
tc - 1:
3 3 1
1 2 3
2 3 2
3 1 -10

output : negative cycle

tc - 2:

6 6 1
1 3 2
1 4 4
3 4 1
2 3 10
4 5 7
4 6 5

output :
0 inf 2 3 10 8

complexity :
O(N * E)
*/