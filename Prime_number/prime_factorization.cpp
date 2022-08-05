//time complexity=o(nloglog sqrt(n))
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0,x=0;
    cin>>n;
    x=n;
    vector<bool>vec(n+1,true);  //all initialized as prime(true)
    //define which one prime and not(sieve)
    vec[1]=false;
    for(int i=2;i*i<=n;i++){
        if(vec[i]){
            for(int j=i*i;j<=n;j+=i)
                vec[j]=false;
        }
    }
    //now counting part
    int cnt=0;
    int count[n+1] {0}; //all initialized to zero
    for(int i=2;i*i<=n;i++){
        if(vec[i]){
            cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            count[i]=cnt;
        }
    }
    if(n>1){
        count[n]=++count[n];
    }
    //output
    for(int i=2;i<=x;i++){
        cout<<i<<" : "<<count[i]<<endl;
    }

    return 0;
}