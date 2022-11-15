#include<bits/stdc++.h>
using namespace std;


long long multiplication(long long a, long long b,long long m){
    long long res = 0; 
    a %= m;
    while (b) {
        if (b % 2)
            res = (res + a) % m;

        a = (2 * a) % m;
        b >>= 1; 
    }
    return res;
}

long long pow_mod(long long x,long long n,long long m){
    x %= m;
    long long res = 1LL;
    while (n > 0) {
        if (n & 1) res = multiplication(res , x, m);
        x = multiplication(x, x, m);
        n >>= 1;
    }
    return res;
}

long long inverse(long long b, long long m) {
  return pow_mod(b, m - 2, m);
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int a=0,b=0,m=0;
    cin>>a>>b>>m;
    int gc=__gcd(b,m);
    if(gc==1){
        cout<< multiplication(a, inverse(b,m) ,m) <<endl;
    }else{
        cout<<"modular inverse doesn't exist"<<"\n";
    }
    return 0;
}