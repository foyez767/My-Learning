// finding length of longest strictly increasing subsequence
// complexity : O(NlogN) when Ai <= 1e5
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+9, inf = 1e9, M = 1e5 + 9;
int arr[N], tree[4 * M];

int query(int node,int b,int e, int l, int r){
    if(b > r or e < l)
        return -inf;   // *** change this with appropiate value
    if(b >= l and e <= r)
        return tree[node];

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b+e)/2;
 
return max(query(left,b,mid,l,r),query(right,mid+1,e,l,r));
}

void update(int node,int b,int e, int i,int x){
    if(i < b or i > e)
        return;
    if(b == e and b == i){
        tree[node] = max(x, tree[node]);     // ****Update with appropiate value
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (b + e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    //***change this
    tree[node] = max(tree[left] , tree[right]);
}

int length[N];

int main(){
    int n ; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }


    for(int i = 1; i <= n; i++){
        length[i] = 1;

        if(arr[i] != 1) {
            int mx = query(1, 1, M, 1, arr[i] - 1) + 1; //if ith item is taken, strictly less then arr[i]
            length[i] = max(mx, length[i]);
        }
        update(1, 1, M, arr[i], length[i]);
    }
    
    // cout << query(1, 1, N, 1, M) << "\n";

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, length[i]);
    }

    cout << ans << "\n";
    
return 0;
}