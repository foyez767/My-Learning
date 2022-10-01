//all prime numbers between 1 to n
//prime number in a range
//**sieve of eratosthenes
//time complexity: O(NloglogN)
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    int n=0;
    cin>>n;
    vector<bool>vec (n+1,true);
    vec[0]=vec[1]=false;
    //cutting all multiples 
    for(long long i=2;i*i<=n;i++){
        if(vec[i]==true){       // start i from 2 and marks all multiples of i as not prime
            for(long long j=i*i;j<=n;j+=i)
                vec[j]=false;
        }
    }
    //all prime numbers between 1 to n
    for(long long i=1;i<=n;i++){
        if(vec[i]==true)
            cout<<i<<" ";
    }    
    return 0;
}
//if(condition er value '0' mane false,onno sov value'r jonno eta true)