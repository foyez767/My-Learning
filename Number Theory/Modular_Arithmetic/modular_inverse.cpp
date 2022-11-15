//this code is to determine : (a/b)mod m=(a*b^-1)mod m
//first check gcd of (b,m) is 1 or not,if 1 then m is prime else m is not prime(inverse not possible)
//b^-1=b^(m-2) mod m ;;determine it by using x^n mod m function then apply modular aritmetc rules
//when multplying
//this algorithm using recursion ,so for big data it is little bit slower 
#include<bits/stdc++.h>
using namespace std;

long long pow_mod(int x,int n,int m){
    if (n==0)
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
  
    int a=0,b=0,m=0;
    cin>>a>>b>>m;
    int gc=__gcd(b,m);
    if(gc==1){
        //determine b invers 1
        long long c=pow_mod(b,m-2,m);
        //let b^-1=c
        //(a*c)mod m=((a%m)*(c%m))%m
        long long product=((a%m)*(c%m))%m;
        cout<<product<<"\n";
        // cout<<c<<endl;

    }else{
        cout<<"modular inverse doesn't exist"<<"\n";
    }
    return 0;
}