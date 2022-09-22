#include<bits/stdc++.h>
#define ll long long
#define nn "\n"
using namespace std;

  
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
ll n=0;
cin>>n;
if((n&(n-1))==0) cout<<n<<" is a power of 2"<<endl;
else cout<<n<<" is not a power of 2"<<endl;
  
    
    return 0;
}