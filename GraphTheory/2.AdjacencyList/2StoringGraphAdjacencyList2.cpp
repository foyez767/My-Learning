//suppose it is required to check if there is an edge between (u,v) exist or not
//we can check it in log(N) time while using  adjacency list
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
// vector<set<int>> grp(N);

set<int> grp[N];

int main(){
    int n, e;   cin >> n >> e;

    int u, v;
    for(int i = 1; i <= e; i++){
        cin >> u >> v;
        grp[u].insert(v);
        grp[v].insert(u);
    }

    cout << "Which edge to check : ";   cin >> u >> v;

    if(grp[u].find()) 
        cout << "Exist\n";
    else 
        cout << "Not exist\n";

    return 0;
}