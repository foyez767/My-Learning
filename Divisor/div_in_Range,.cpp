//count divisor of all numbers between 1 to n
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n=0;
cin>>n;
int div[n+1] {0};
//for every numbers from 1 to n
for(int i=1;i<=n;i++){
    // Increase divisors count for every number divisible by i
    for(int j=1;j*i<=n;j++){
        div[i*j]++;
    }
}
//print the divisor
for(int i=1;i<=n;i++)
    cout<<i<<" : "<<div[i]<<" \n";
  
    
    return 0;
}