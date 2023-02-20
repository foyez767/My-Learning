//complexity for all operation independently is log(n) in base 2
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int arr[N],tree[4*N];   // arr where the elements are stored and tree is where value of a certain range is stored
//remember we can have at most 4n nodes ****

// node = which node , b and e refers to the range of node
void build(int node,int b, int e){
    if(b == e){ // when b and e is equal means it is a leaf node and hence we don't have any child so don't go
        tree[node] = arr[b];
        return;
    }
    int left = 2 * node, right = 2 * node +1;
    int mid = (b+e) / 2;
    build (left, b, mid);
    build (right, mid+1, e);
    tree[node] = tree[left] + tree[right];  //*** change this
}

//which node and its range[b,e]
//query range [l,r]
int query(int node,int b,int e, int l, int r){
    if(b > r or e < l)  // if node lies wholly outside the range
        return 0;   // returns apporipiate value
     if(b >= l and e <= r)   // if node lies wholly inside the range
        return tree[node];
    //node lies partially inside the range then we need to go its left and right child
    int left = 2 * node, right = 2 * node +1;
    int mid = (b+e) / 2;
    return query(left,b,mid,l,r) + query(right,mid+1,e,l,r);    // *** change this 
}

// current node range
//change value of arr[i] = x
void update(int node, int b, int e, int i, int x){
// if i is out of range for current node
    if(b > i or e < i)
        return;
//if it is a leaf node and at the same time it is our expected node
    if(b == e and b == i){
        tree[node] = x; // update
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b+e) / 2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
// *** change this
    tree[node] = tree [left] + tree[right]; // arr[i]  jekhane jekhane ache tader value change kora 
}

int main(){

    int n;      cin >> n;   // n = no of elements

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1,1,n);   //for first node b = 1 ,e = n
    // for(int i = 1; i <=4* n; i++)
    //     cout << tree[i] << " ";
    cout << query(1,1,n,2,6) << endl;

    update(1,1,n,2,6); // arr[2] = 6
    cout << query(1,1,n,2,6) << endl;

    return 0;
}