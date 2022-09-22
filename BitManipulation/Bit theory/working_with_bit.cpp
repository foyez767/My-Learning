#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getIthbit(ll n,ll i){
    ll ans=0,mask=0;
    mask=(1<<i);
    if(n&mask>0)
     ans=1;
    else 
    ans=0;

    return ans;
}
ll clearIthbit(ll n,ll i){
    ll mask= ~(1<<i);
    n=n&mask;
return n;
}

ll setIthbit(ll n,ll i){
    ll mask=(1<<i);
     n=(n|mask);

    return n;
}
//val refers to the value(0 or 1) by which we want to update ith bit
ll updateIthbit(ll n,ll i,ll val){
    //if ith bit is 1 we need to do clear the ith bit to 0
    ll mask=~(1<<i);
    n=n&mask;
    //now we are changing the ith bit
    mask=(val<<i);
    n=(n|mask);

    return n;
}
ll clearibits(ll n,ll i){
    ll mask=(-1<<i);
    // ll mask=((~0)<<i);
    n=n&mask;
return n;
}

ll clearbitsInRange(ll n,ll i,ll j){
    ll a=-1<<(j+1);
    ll b=(1<<i)-1;
    ll mask=a|b;
    n=n&mask;
return n;
}

  
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
ll n=0,i=0,j=0;
cin>>n>>i;
// cin>>n>>i>>j;
cout<<i<<" th bit of "<<n<<" is: ";
cout<<getIthbit(n,i)<<endl;
// cout<<"n is now: "<<clearIthbit(n,i)<<endl;
// cout<<"n is now: "<<setIthbit(n,i)<<endl;
// cout<<"n is now: "<<updateIthbit(n,i,0)<<endl;
// cout<<"n is now: "<<clearibits(n,i)<<endl;
// cout<<"n is now: "<<clearbitsInRange(n,i,j)<<endl;
  
    
    return 0;
}