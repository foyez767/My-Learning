#include<bits/stdc++.h>
#define ll long long
#define nn  "\n"
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    int n=0;
    cin>>n;
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=log10(i);
    }
    ll digit=floor(sum)+1;
    cout<<digit<<endl;
    return 0;
}