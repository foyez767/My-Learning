//determine all factors of a given integar n
//time complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            cout<<i<<" ";
    }

    return 0;
}