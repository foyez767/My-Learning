#include<bits/stdc++.h>
#define ll long long
#define nn "\n"
using namespace std;

//complexity for this loop is: log(n)
ll cout_bits(ll n){
    ll cnt=0;
    while(n>0){
        int last_bits=(n&1);
        cnt+=last_bits;

        n=n>>1;
    }
return cnt;
}

ll cout_bits_fast(ll n){
    ll cnt=0;
    while(n>0){
        //removes the last set bits from n
        n=n&(n-1);
        cnt++;
    }
return cnt;
}

  
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
ll n=0;
cin>>n;
cout<<cout_bits(n)<<nn;
cout<<cout_bits_fast(n)<<nn;
    
    return 0;
}