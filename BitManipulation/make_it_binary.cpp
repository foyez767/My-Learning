#include<bits/stdc++.h>
#define ll long long
#define nn "\n"
using namespace std;

void makeItbinary_own(ll n){
    vector<ll>vec;
    if(n==0) vec.push_back(0);
    while(n>0){
        vec.push_back(n%2);
        n/=2;
    }
    for(int i=vec.size()-1;i>=0;i--)
        cout<<vec[i];
    cout<<nn;
}
//10(0)+10(1)+10(2)+....
ll make_it_binary(ll n){
    ll bin=0,p=1;
    while(n>0){
        ll last_bit=(n&1);
        bin+=(last_bit*p);
        
        p*=10;
        n=(n>>1);
    }
return bin;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
ll n=0;
cin>>n;
    makeItbinary_own(n);
    cout<<make_it_binary(n)<<nn;

    
    return 0;
}