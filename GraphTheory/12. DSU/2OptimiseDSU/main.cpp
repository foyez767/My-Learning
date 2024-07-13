//Optimisation based on path compression + by size 
//complexity of findSet function: O(1)
//hence unionSet() time complexity is also : O(1)
#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<pair<int,int>> edgeList;
int parent[N], sz[N];

void make_set (int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findSet(int i){
    if (parent[i] == i) {
       return i; 
    }
return parent[i] = findSet(parent[i]);
}

void unionSet(int x, int y){
    int a = findSet(x);
    int b = findSet(y);

    if (sz[a] < sz[b]) swap(a, b);

    if (a != b) {
        parent[b] = a;
        sz[a] += sz[b];
    }

}

int main(){
    int n, e; cin >> n >> e;

    for(int i = 1; i <= e; i++) {
        int u, v; cin >> u >> v;
        edgeList.push_back({u, v});
    }

    make_set(n);

    for(auto p : edgeList){
        int u = p.first, v = p.second;

        unionSet(u, v);
    }

    cout << "Nodes  Representive\n";

    for(int i = 1; i <= n; i++){
        cout << i << "         " << parent[i] << "\n";
    }


return 0;
}

/*
input:
10 8
1 2
6 7
6 9
8 7
1 3
2 4
3 5
4 5
*/