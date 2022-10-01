//prime sum
//You are given a number n. Find all the pairs (l, r) such that l <=r where l,r are prime numbers
//and their sum is also prime and no more than n.
#include<bits/stdc++.h>
using namespace std;

long long sieve(long long n){
    vector<long long> vec(n+1,true);
    vec[0]=vec[1]=false;
    for(long long i=2; i*i <=n;i++){
        if(vec[i]){
            for(long long j=i*i; j<=n ;j+=i)
                vec[j]=false;
        }
    }

    vector<long long>primes;
    for(long long i=0; i<vec.size(); i++){
        if(vec[i])
            primes.push_back(i);
    }
    long long cnt=0,x=0;
    for(long long i=0; i<(primes.size()-1);i++){
        for(long long j=i+1;j<primes.size();j++){
            x=primes[i]+primes[j];
            if(x<=n and vec[x]==true)
                cnt++;
        }
    }
return cnt;
}

int main(){
    long long n;
    cin>>n;
    cout<<sieve(n)<<endl;

    return 0;
}