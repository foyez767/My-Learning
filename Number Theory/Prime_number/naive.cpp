//print all prime numbers between 1 to n
//time complexity=O(n*sqrt(n))
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){//n prime or not check this function
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);  
    int n=0;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(isPrime(i))
            cout<<i<<" ";
    }
    return 0;
}