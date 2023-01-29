//Given an integer n and a number p which is NOT prime, find the largest x such that p^x divides n!
#include<bits/stdc++.h>
using namespace std;

//Given an integer n and a prime number p, find the largest x such that p^x divides n!
long long legendre(long long n, long long p){
    long long ans = 0;
    while(n){
        ans += n/p;
        n /= p;
    }
return ans;
}

void primeFactor(vector<pair<int,int>> &vec, int n){
    for(int i = 2; i * i <= n; i++){
        if(! (n % i)){
            int cnt = 0;
            while(! (n % i)){
                cnt ++;
                n /= i;
            }
        vec.push_back(make_pair(i,cnt));
        }
    }
    if(n > 1)
        vec.push_back(make_pair(n,1));
}

int main(){
    long long n , k , mini = LONG_MAX;    cin>> n >> k;
    vector<pair<int,int>> pFactor;

    primeFactor(pFactor, k);    //determines all factor of k
    //ans is equal min of y / x where y = legendre (n , prime factor) and x = how many times this factor is present 
    for(auto v: pFactor){
        long long x = v.second;
        long long y = legendre(n,v.first);
        mini = min(mini, y/x);
    }

    cout << mini << endl;

    return 0;
}
