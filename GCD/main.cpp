//determining gcd of two integar
//time complexity:O(log max(a,b))
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int a=0,b=0,min=0,gcd=0;
    cin>>a>>b;
    // (a>b)? min=b:min=a;
    // for(int i=1;i<=min;i++){
    //     if(a%i==0 && b%i==0)
    //         gcd=i;
    // }
    // cout<<gcd<<"\n";
    cout<<__gcd(a,b)<<endl;;

    return 0;
}
