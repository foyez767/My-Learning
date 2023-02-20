#include<bits/stdc++.h>
#define ll long long
#define INF INT64_MAX
using namespace std;

const ll N = 1e5+9;
ll arr[N];
pair<ll,ll> tree[4*N];

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first < b.first)
        return a;
    if(a.first > b.first)
        return b;
return make_pair(a.first, a.second + b.second);
}

void build(ll node,ll b,ll e){
    if(b == e){
        tree[node] = make_pair(arr[b],1);
        return;
    }
    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b + e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    //***change this
    tree[node] = combine(tree[left],tree[right]);
}

pair<ll,ll> query(ll node,ll b,ll e, ll l, ll r){
    if(b > r or e < l)
        return make_pair(INF,0);   // *** change this with appropiate value
    if(b >= l and e <= r)
        return tree[node];

    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b+e)/2;
 
return combine(query(left,b,mid,l,r),query(right,mid+1,e,l,r));
}

void update(ll node,ll b,ll e, ll i,ll x){
    if(i < b or i > e)
        return;
    if(b == e and b == i){
        tree[node] = make_pair(x,1);     // ****Update with appropiate value
        return;
    }

    ll left = 2 * node, right = 2 * node + 1;
    ll mid = (b + e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    //***change this
    tree[node] = combine(tree[left],tree[right]);
}

void solve(){
    ll n,a,q,l,r;   cin >> n >> q;

    for(ll i = 1; i <= n; i++)  cin >> arr[i];

    build(1,1,n);

    while(q--){
        cin >> a >> l >> r;

        if(a == 1)
            update(1,1,n,l+1,r);
        else{
            pair<ll,ll> p = query(1,1,n,l+1,r);
            cout << p.first << " " << p.second << "\n";
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