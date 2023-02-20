#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int arr[N] ,tree[4*N],lazy[4*N];

void pull(int node){
    int left = 2 * node, right = 2 * node + 1;
    tree[node] = tree[left] + tree[right];
}

void push(int node,int b,int e){
    if(lazy[node] == 0) return;
    tree[node] += lazy[node] * (e - b + 1);

    if(b != e){
        int left = 2 * node, right = 2 * node + 1;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    lazy[node] = 0;
}

long long combine(long long a,long long b){
    return a + b;
}

void build(int node,int b,int e){
    lazy[node] = 0;     
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (b+e) / 2;
    build(left,b,mid);
    build(right,mid+1,e);
    pull(node);
}

void update(int node,int b,int e,int l,int r,int x){
    push(node,b,e);

    if(b > r or e < l) return;
    if(b >=l and e <= r){
        lazy[node] = x; // set lazy or value of propagation
        push(node,b,e);
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b+e) / 2;
    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);

    pull(node);
}
int query(int node,int b,int e,int l,int r){
    push(node,b,e);

    if(b > r or e < l) return 0;
    if(b >= l and e <= r)
        return tree[node];

    int left = 2 * node, right = 2 * node +1;
    int mid = (b+e) / 2;

return combine(query(left,b,mid,l,r),query(right,mid+1,e,l,r));
}

int main(){
    int n;  cin >> n;

    for(int i = 1; i <= 5; i++) cin >> arr[i];

    build(1,1,n);

    cout << query(1,1,n,2,4) << endl;

    update(1,1,n,2,4,10);

    cout << query(1,1,n,2,4) << endl;

    return 0;
}