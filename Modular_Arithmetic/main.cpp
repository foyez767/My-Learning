//this code is useful to determine x^n mod m
#include<bits/stdc++.h>
#define mod 5    //change this value according to the number by which we are dividing
using namespace std;

long long pow_mod(int x,int n,int m){
    if(n==0)
        return 1;
    long long t=pow_mod(x,n/2,m);
    if(n%2==0)
        return t*t%m;
    else
        return x*t*t%m;

}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int x=0,n=0;//x=number,n=power
    cin>>x>>n;
    cout<<pow_mod(x,n,mod)<<"\n";
    return 0;
}