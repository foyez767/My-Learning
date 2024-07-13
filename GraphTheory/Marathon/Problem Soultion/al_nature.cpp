#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
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
    int c, r; 

    while (cin >> c >> r and !(c == r and c == 0)) {
        map<string, int> id;

        for (int i = 1; i <= c; i++) {
            string name; cin >> name;
            id[name] = i;
        }

        make_set(c);

        for (int i = 1; i <= r; i++) {
            string u, v; cin >> u >> v;

            unionSet(id[u], id[v]);

            int reps = findSet(id[u]);
        }

        int ans = 0;

        for (int i = 1; i <= c; i++) {
            ans = max (ans, sz[i]);
        }

        cout << ans << "\n";
    }

return 0;
}