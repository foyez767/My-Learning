//complexity: O(sqrt(N))
//prime factor of n
#include<iostream>
using namespace std;

int main(){
    int n=0,cnt=0;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            cout<<i<<" : "<<cnt<<endl;
        }
    }
    if(n>1) cout<<n<<" : "<<1<<endl;
}