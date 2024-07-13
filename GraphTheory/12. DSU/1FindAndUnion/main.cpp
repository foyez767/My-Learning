#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<pair<int,int>> edgeList;
int parent[N];

//complexity: O(N) in worst case
int findSet(int i){
    if(parent[i] == -1){
        return i;
    }
return findSet(parent[i]);
}

//complexity depends on findSet() function hence O(N)

void unionSet(int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
    
    if(s1 != s2){
        parent[s1] = s2;        //parent[s2] = s1 is also correct
    }
}

int main(){
    memset(parent, -1, sizeof(parent));
    int e; cin >> e;    // no of edge

    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        edgeList.push_back({u, v}); 
    }

    for(auto p : edgeList){
        int u = p.first, v = p.second;
        unionSet(u, v);     // make u and v friends
    }

    for(int i = 1; i <= 10; i++){
        cout << parent[i] << " ";
    }

return 0;
}