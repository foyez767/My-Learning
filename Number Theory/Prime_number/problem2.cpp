#include<bits/stdc++.h>
#define n 100000
using namespace std;

vector<long long> closet_divisor(long long num){
// void closet_divisor(long long num){

    //sieve
    vector<long long> vec(n+1,true);
    vec[0]=vec[1]=false;
    for(long long i=2; i*i <=n;i++){
        if(vec[i]){
            for(long long j=i*i; j<=n ;j+=i)
                vec[j]=false;
        }
    }
//separating all primes
    vector<long long>primes;
    for(long long i=0; i<vec.size(); i++){
        if(vec[i])
            primes.push_back(i);
    }
//output
vector<long long> ans;
long long x=0,y=0,flag=0;
    for(long long i=0;i<(primes.size());i++){
        for(long long j=0; j<primes.size(); j++){
            x=primes[i]*primes[j];
            if(x>num+2) break;
            if(abs(num-x)==1){
                if(ans.size()!=0 &&  (abs(ans[0]-ans[1])>abs(primes[i]-primes[j]))){
                    ans.clear();
                    ans.push_back(primes[i]);
                    ans.push_back(primes[j]);
                }
                if(ans.size()==0){
                    ans.push_back(primes[i]);
                    ans.push_back(primes[j]);
                }
                
            }
            if(abs(num-x)==2){
                if(ans.size()!= 0) continue;
                ans.push_back(primes[i]);
                ans.push_back(primes[j]);
            }

        }
    }
    sort(ans.begin(),ans.end());
return ans;
}

int main(){
    long long num=0;
    cin>>num;
    // closet_divisor(num);
    

    return 0;
}