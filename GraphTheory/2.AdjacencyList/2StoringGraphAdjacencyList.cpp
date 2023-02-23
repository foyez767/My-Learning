//adv: memory efficient
//dis: can't check edge between u and v exist or not in O(1)
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> grp[N],cost[N];

int main(){
    int n, e, c = 1;   cin >> n >> e;

    int u,v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].push_back(v);    // (u,v)
        grp[v].push_back(u);    //**applicable for bidirectional graph only
        cost[u].push_back(c);   // if it is a weighted graph, then we need to store cost
        cost[v].push_back(c);
    }
    //edges with 1 and x
    for(auto x : grp[1]){
        cout << x << "\n";
    }   

    //degree
    for(int i = 1; i <= n; i++){
        cout << grp[i].size() << "\n";
    }

    return 0;
}