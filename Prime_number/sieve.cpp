//all prime numbers between 1 to n
//**sieve of eratosthenes
//time complexity;0(nloglogn)
#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    int n=0;
    cin>>n;
    vector<bool>vec (n+1,true);
    vec[1]=false;
    //cutting all multiples 
    for(int i=2;i*i<=n;i++){
        if(vec[i]==true){// jodi condition false hy,tar mane amr age mark kora hyse,tai ar dhukbe na
            for(int j=i*i;j<=n;j+=i)
                vec[j]=false;
        }
    }
    //all prime numbers between 1 to n
    for(int i=1;i<=n;i++){
        if(vec[i]==true)
            cout<<i<<" ";
    }    
    return 0;
}
//if(condition er value '0' mane false,onno sov value'r jonno eta true)