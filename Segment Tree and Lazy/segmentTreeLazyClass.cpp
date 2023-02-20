#include<bits/stdc++.h>
using namespace std;

class segTree{
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    public:
      int n;
      vector<int>arr;
      vector<int>tree;
      vector<int>lazy;

    //Constructor
    segTree(int x){
        n = x;
        arr.resize(n + 1, 0);
        tree.resize(4 * (n + 1), 0);
        lazy.resize(4 * (n + 1), 0);
    }
    //Destructor
    ~segTree(){
      arr.clear();
      tree.clear();
      lazy.clear();
    }
    //taking input: index based on 1
    void input(){
       for(int i = 1; i <= n; i++)
            cin >> arr[i];
    }
//pull function
    void pull(int node){
        tree[node] = tree[lc] + tree[rc];   //***change this
    }
// combine function
    int combine(int a, int b){
      return (a + b);   //***change this
    }
//push function
    void push(int node, int b, int e){
      if(lazy[node] == 0)   // *** change this
        return;

      tree[node] = tree[node] + lazy[node] * (e - b + 1);   //***change this

      if(b != e){
        lazy[lc] = lazy[lc] + lazy[node];
        lazy[rc] = lazy[rc] + lazy[node];
      }

      lazy[node] = 0;   // *** change this
    }

// build function
    void build(int node, int b, int e){
        lazy[node] = 0;   // change with appropriate value

        if(b == e){
            tree[node] = arr[b];
          return;
        }

        int mid = (b + e) / 2;

        build(lc, b, mid);
        build(rc, mid+1, e);

        pull(node);
    }
//update function
    void update(int node, int b, int e, int l ,int r, int x){
        push(node, b, e);

        if(b > r or e < l)
          return;
        
        if(b >= l and e <= r){
            lazy[node] = x;     //***set lazy or value of propagation
            push(node, b, e);
        }

        int mid = (b + e) / 2;

        update(lc, b, mid, l, r, x);
        update(rc, mid + 1, e, l, r ,x);

        pull(node);
    }

//query funciton
    int query(int node, int b, int e, int l, int r){
        push(node, b, e);

        if(b > r or e < l)
            return 0;   //***change this

        if(b >= l and e <= r)
            return tree[node];

        int mid = (b + e) / 2;

      return combine(query(lc, b, mid, l, r), query(rc, mid + 1, e, l, r));
    }
};


void solve(){
    int n;    cin >> n;
    segTree t(n);
    t.input();
    t.build(1,1,n);
}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= t; i++){
    solve();
  }
  
  return 0;
}