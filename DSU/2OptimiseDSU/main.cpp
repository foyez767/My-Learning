//Optimisation based on path compression, 
//complexity of findSet function: O(1)
//hence unionSet() time complexity is also : O(1)
#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<pair<int,int>> edgeList;
int parent[N];

int findSet(int i){
    if(parent[i] == -1)
        return i;

return parent[i] = findSet(parent[i]);
}

void unionSet(int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);

    if(s1 != s2){
        parent[s1] = s2;
    }
}

int main(){
    memset(parent, -1, sizeof(parent));

    int e; cin >> e;

    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        edgeList.push_back({u, v});
    }

    for(auto p : edgeList){
        int u = p.first, v = p.second;

        unionSet(u, v);
    }

    for(int i = 1; i <= 10; i++){
        cout << parent[i] << " ";
    }
    cout << endl;

    cout << findSet(1) << endl;

    for(int i = 1; i <= 10; i++){
        cout << parent[i] << " ";
    }
    cout << endl;

return 0;
}

/*
input:
5
1 2
1 3
2 4
3 5
4 5
*/