#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5 + 7;
ll arr[N],tree[4*N],lazy[4*N];

void pull(ll node){
    ll left = 2 * node, right = 2 * node + 1;
    tree[node] = (tree[left] + tree[right]);    // *** change this
}
 
void build(ll node,ll b,ll e){
    lazy[node] = 0;     // *** change this
    if(b == e){
        tree[node] = arr[b];
        return;
    }

    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b + e) / 2;
    build(left,b,mid);
    build(right,mid+1,e);

    pull(node);
    }

void push(ll node, ll b, ll e){     // *** change this
    if(lazy[node] == 0)
        return;
    tree[node] = tree[node] + lazy[node] * (e - b + 1);

    if(b != e){
        ll left = 2 * node, right = 2 * node + 1;
        lazy[left] = lazy[left] + lazy[node];
        lazy[right] = lazy[right] + lazy[node];
    }
 
    lazy[node] = 0;
}
 
ll combine(ll a, ll b){ // *** change this
    return (a+b);
}
 
void update(ll node,ll b,ll e,ll l,ll r,ll x){
    push(node,b,e);
 
    if(b > r or e < l)
        return ;
    if(b >= l and e <= r){
        lazy[node] = x;     //***set lazy or value of propagation
        push(node,b,e);
    return;
    }
 
    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b + e) / 2;
    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);
 
    pull(node);
}
 
ll query(ll node,ll b,ll e,ll l,ll r){
    if(b > r or e < l)
        return 0;		//***change this
    if(b >= l and e <= r)
        return tree[node];
 
    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b + e) / 2;
return combine(query(left,b,mid,l,r),query(right,mid+1,e,l,r));
}

void solve(){
    int n,a,q,l,r,x;  cin >> n >> q;
    for(int i = 1; i <= n; i++) arr[i] = 0;

    build(1,1,n);
    while(q--){
        cin >> a ;
        if(a == 1){
            cin >> l >> r >> x;
            update(1,1,n,l+1,r+1,x);
        }else{
            cin >> l;
            cout << query(1,1,n,l+1,l+1) << "\n";
        }
    }
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}