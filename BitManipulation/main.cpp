//**********In the name of Allah, most Gracious and Merciful******
#include<bits/stdc++.h>
#define ll long long
#define nn "\n"
using namespace std;

void solve(){
    ll n=8,x=0,flag=0,cnt=0,x1=0,x2=0,x3=0,x4=0,y1=0,y2=0,y3=0,y4=0,diff=0;
    cin>> x1>> y1>> x2>> y2>> x3>> y3>> x4>> y4;

    if(x1==x2 and x3==x4){
        if(y2-y1!=y3-y4 or y2-y1==0 or y3-y4==0) flag=1;
    }else if(x1==x3 and x2==x4){
        if(y3-y1!=y2-y4 or y2-y4==0 or y1-y3==0) flag=1;

    }else if(x1==x4 and x2==x3){
        if(y1-y4!=y2-y3 or y2-y3==0 or y1-y4==0) flag=1;
    }else flag=1;

    if(flag==1) cout<<"NO"<<nn;
    else cout<<"YES"<<nn;
 
 }
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
ll t=1;
cin>>t;
while(t--)   solve();
    
    return 0;
}