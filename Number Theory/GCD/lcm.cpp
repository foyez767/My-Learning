#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int a=0,b=0,gcd=0,lcm=0;
    cin>>a>>b;
    gcd=__gcd(a,b);
    lcm=(a*b)/gcd;
    cout<<lcm<<endl;
    
    return 0;
}