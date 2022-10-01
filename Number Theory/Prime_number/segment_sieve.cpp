#include<bits/stdc++.h>
#define ll long long
#define n 100000
using namespace std;

vector<bool> vec(n+1,true);

void sieve(vector<long long>& all_prime){
    for(long long i=2; i<=n; i++){
        if(vec[i]){
            all_prime.push_back(i);
            for(long long j=i*i; j<=n; j+=i)
                vec[j]=false;
        }       
    }
}

int main(){
    vector<long long>all_prime;
    sieve(all_prime);
    long long x=0,y=0;
    cin>>x >>y;
//***main code
    vector<long long>segment(y-x+1,0);
    for(auto p: all_prime){
        //stop when p*p>n 
        if(p*p>n) 
            break;
    //otherwise we need to find the nearest starting point
        long long start=(x/p)*p;

        if(p>=x && p<=y) 
            start=2*p;

        //start marking the number as not prime from start
        for(long long j=start; j<=y; j+=p){
            if(j<x) continue;
            //crossing out the number which is not prime
            segment[j-x]=1;
        }
    }
//output
    for(long long i=x; i<=y; i++){
        if(segment[i-x]==0 and i!=1)
            cout<< i <<" ";
    }
}