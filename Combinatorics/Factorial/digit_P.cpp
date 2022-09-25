#include<bits/stdc++.h>
#define ll long long
#define nn  "\n"
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    int num=0,p=0,i=1;
    cin>>num>>p;
    int count_p=0;
    while(1){
        count_p+=(num/pow(p,i));
        if((num/pow(p,i))==0)
            break;
        i++;
    }
    cout<<count_p<<endl;
    
    return 0;
}