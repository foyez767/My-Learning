#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
int arr[N], tree[4*N], length[N];

int combine(int a,int b){
    return max(a , b); // *** change this
}

void build(int node,int b,int e){
    if(b == e){
        tree[node] = arr[b];	//***change this
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (b + e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    //***change this
    tree[node] = max(tree[left] , tree[right]);
}

int query(int node,int b,int e, int l, int r){
    if(b > r or e < l)
        return 0;   // *** change this with appropiate value
    if(b >= l and e <= r)
        return tree[node];

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b+e)/2;
 
return combine(query(left,b,mid,l,r),query(right,mid+1,e,l,r));
}

void update(int node,int b,int e, int i,int x){
    if(i < b or i > e)
        return;
    if(b == e and b == i){
        tree[node] = max (x, tree[node]);     // ****Update with appropiate value
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b + e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    //***change this
    tree[node] = max(tree[left] , tree[right]);
}

void solve(){
    int n; cin >> n;

    set <int> se;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        se.insert(arr[i]);
    }

    //array compression
    map<int,int> id;
    auto it = se.begin();
    int cnt = 0;

    while (it != se.end()) {
        id[*it] = ++cnt;
        it++;
    }

    //finding length of LIS
    for (int i = 1; i <= n; i++) {
        int idx = id[arr[i]];

        length[idx] = 1;

        if (idx != 1) {
            int mx = max (length[idx], query(1, 1, N, 1, idx - 1) + 1);

            length[idx] = max (mx, length[idx]);
        }

        update(1, 1, N, idx, length[idx]);
    }

    cout << query(1, 1, N, 1, N) <<  "\n";

 
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}