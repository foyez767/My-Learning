//adv: check if two nodes u and v have an edge or not in O(1)
//dis : for sparse graph, it requires too much space
#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int grp[N][N];

int main(){
    int n, e;   cin >> n >> e;  // n = no of nodes ; e = no of edge

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u][v] = 1;      //(u,v) have an edge
        grp[v][u] = 1;      //for bidirectional graph it is applicable since (u,v) = (v,u)
    }
    cout << "You want to check : "; cin >> u >> v;

    if(grp[u][v] == 1){
        cout << "YES! " << u << " and " << v << "share an edge." << endl;
    }else cout << "NO edge between " << u << " and " << v << endl; 


    return 0;
}