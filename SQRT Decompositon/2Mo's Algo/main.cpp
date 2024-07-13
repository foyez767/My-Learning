//PROBLEM: SPOJ DQUERY(YKW DATA STRUCTURES SECTION)
//indexing 0 based
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7,mx = 1e6 + 7;
int arr[N], cnt[mx], distinct = 0;

class query{
    public:
    int l, r, ans, id, block;
    //operator overloading
    bool operator< (query P) const {
        return make_pair(this->block, this-> r) < make_pair(P.block, P.r);
    }
} q[N];

bool comp(query a, query b){
    return a.id < b.id;
}

void add(int val){
    cnt[val]++;
    if(cnt[val] == 1) distinct++;
}

void remove(int val){
    cnt[val]--;
    if(cnt[val] == 0) distinct--;
}

int main(){
    int n, m, queries; cin >> n;    // no of elements

    m = sqrt(n);    //no of blocks and no of elements in each blocks

//input
    for(int i = 0; i < n; i++) cin >> arr[i];

    cin >> queries; // no of query
//query input
    for(int i = 0; i < queries; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--; // for 0 based indexing, if it is 1 based, then don't need to decrement it
        q[i].id = i, q[i].block = q[i].l / m;
    }
//sorting the quereies
    sort(q, q + queries);
//processing the queries
    int x = 0, y = 0;
//[x,y) = x inclusive, y is not inclusive
    for(int i = 0; i < queries; i++){
        //adding y//moving right
        while(y <= q[i].r){
            add(arr[y]);
            y++;
        }
        //removing y// moving left
        while(y > q[i].r + 1){
            y--;
            remove(arr[y]);
        }

        //removing x // moving right
        while(x < q[i].l){
            remove(arr[x]);
            x++;
        }
        //addding x // moving left
        while(x > q[i].l){
            x--;
            add(arr[x]);
        }

        //distinct between[x, y) = answer for the query
        q[i].ans = distinct;
    }

    //now I need to go back to my initial query order
    sort(q, q + queries, comp);
    
    //printing answer
    for(int i = 0; i < queries; i++){
        cout << q[i].ans << "\n";
    }
return 0;
}