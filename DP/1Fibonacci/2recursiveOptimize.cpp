//complexity : O(n)
#include<bits/stdc++.h>
using namespace std;

const int N = 50;
int f[N];
bool isComputed[N];

long long fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(isComputed[n])
        return f[n];

    f[n] = fibo(n - 1) + fibo (n - 2);
    
    isComputed[n] = true;
return f[n];
}
int main(){
    int n; cin >> n;
    cout << fibo(n) << "\n"; 

return 0;
}