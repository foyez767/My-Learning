//determine divisor of a given integar
//complexity: O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i!= (n/i))
                cout<<n/i<<" ";
        }            
    }

    return 0;
}