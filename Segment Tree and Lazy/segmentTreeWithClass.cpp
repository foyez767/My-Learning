#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

class segTree{
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    public:
        int n;  
        vector<int>arr;
        vector<int>tree;
    //constructor
    segTree(int x){
        n = x;
        arr.resize(n + 1, 0);
        tree.resize(4 * (n + 1), 0);
    }
    //Destructor
    ~segTree(){
        arr.clear();
        tree.clear();
    }
    //taking input in arr : indexing is based on 1
    void input(){
      for (int i = 1; i <= n; i++) 
          cin >> arr[i];
    }
    ///******************************
//combine function
    int combine (int a, int b){
        return (a + b);     //***change this
    }
//pull() function
    void pull (int node){
        tree[node] = tree[lc] + tree[rc];   //***change this function as far requirement
    }
//build function
    void build (int node, int b, int e){
        if(b == e){
            tree[node] = arr[b];    //***change this
            return;
        }

        int mid = (b + e) / 2;
        
        build (lc, b, mid);
        build (rc, mid + 1, e);

        pull (node);
    }
// update function
    void update (int node, int b, int e, int i, int x){
        if(i < b or i > e)
            return;

        if(b == e and b == i){
            tree[node] = x;     //***update with appropiate value
        return;
        }

        int mid = (b + e) / 2;

        update (lc, b, mid, i, x);
        update (rc, mid + 1, e, i, x);

        pull (node);
    }
//query function
    int query (int node, int b, int e, int l, int r){
        if(b > r or e < l)
            return 0;       //***return appropriate value
        
        if(b >= l and e <= r)
            return tree[node];

        int mid = (b + e) / 2;

    return combine(query(lc, b, mid, l, r), query(rc, mid + 1, e, l, r));
    }
};

void solve(){
    int n; cin >> n;
    segTree t (n);

    t.input();
    t.build(1, 1, n);
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}