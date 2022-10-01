//Given an integer n, return the number of prime numbers that are strictly less than n
//all prime numbers in a range
#include<bits/stdc++.h>
#define ll long long
#define n 50000001
#define nn "\n"
using namespace std;

vector<bool> vec(n+1,true);

void sieve(){
    vec[0]=vec[1]=false;
    for(ll i=2; i*i<=n; i++){
        if(vec[i]){
            for(ll j=i*i; j<=n; j+=i){
                vec[j]=false;
            }
        }
    }
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    ll q=0,x=0,y=0;
    sieve();
    vector<ll> count_prime (n+1,0);
    //prefix sum
    for(ll i=1;i<=n;i++){
        if(vec[i]){
            count_prime[i]=count_prime[i-1]+1;
        }else count_prime[i]=count_prime[i-1];
    }
    cin>>q;
    while(q--){
        // cin>>x >> y;
        //all prime in range of [x,y]
        // cout<<count_prime[y] - count_prime[x-1] <<nn;
        cin>>y;
        if(y==0){
            cout<< 0 <<nn;
            continue;
        }
        cout<<count_prime[y-1]<<nn;
    }
    
    return 0;
}