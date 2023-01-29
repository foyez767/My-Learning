//complexity: O(sqrt(N))
//prime factor of n
#include<bits/stdc++.h>
using namespace std;

// //returns all prime factor of n , pair(smf,cnt)
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
    int n=0,cnt=0;
    cin>>n;
    vector<pair<int,int>> vec;

    primeFactor(vec,n);
    for(auto v: vec)    cout<< v.first << " : " << v.second <<endl;
}