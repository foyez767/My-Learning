// this algo is useful to print all prime factor of a given number
//time complexity= for precomputation :O(NloglogN); for q query : O(QlogN)
//total complexity= O(nloglogn+Qlogn);
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0,x=0;
    cin>>n;
    int count[n+1] {};
    //main code
    for(int i=2; i<=n;i++) count[i]=i;  // marking smallest prime factor for every number to be itself.

    for(int i=2;i*i<=n;i++){
        if(count[i]==i){
            for(int j=i*i;j<=n;j+=i)
                count[j]=i;
        }
    }
    //query: print 
    int q=0,num=0;
    cin>>q;
    while(q--){
        cin>>num;
        cout<<"Prime factor of "<<num<<" is : ";
        while(num!=1){
            cout<<count[num]<<" ";
            num/=count[num];
        }
    }

    return 0;
}