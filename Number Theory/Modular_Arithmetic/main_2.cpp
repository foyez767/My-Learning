#include<bits/stdc++.h>
#define p 5
using namespace std;
//addition
int add(int x,int y){
    return (x+y)%p;
}
//sbutraction
int subm(int x,int y){
    return (((x-y)% p + p)%p);
}
//multiplication
int multim(int x,int y){
    return (x*y)%p;
}

int main(){
    int x,y;
    cin>>x >>y;
    cout<<add(x,y)<<endl;
    cout<<subm(x,y)<<endl;
    cout<<multim(x,y)<<endl;
}