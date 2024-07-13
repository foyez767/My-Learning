#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<pair<int,int>> edgeList;
int parent[N];
bool ok = false;

int findSet(int i){
    if(parent[i] == -1){
        return i;
    }
return parent[i] = findSet(parent[i]);
}

bool checkCycle(int s1,int s2){
    if(s1 != s2)
        return false;
return true;
}

void unionSet(int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);

    if(!checkCycle(s1, s2)){
        parent[s1] = s2;
    }else{
        ok = true;
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

        if(ok){
            cout << "Cycle present\n";
            return 0;
        }
    }

    cout << "NO cycle\n";

return 0;
}

/*
5
1 2
1 3
2 4
3 5
4 5

*/