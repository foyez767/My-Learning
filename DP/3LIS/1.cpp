// finding length of longest strictly increasing subsequence
//complexity: O(n * n)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int length[N];

int main(){
    int n ; cin >> n;

    int arr[n + 1] {};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        length[i] = 1;  
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], 1 + length[j]);  // ith item take
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, length[i]);
    }

    cout << ans << "\n";
    
return 0;
}