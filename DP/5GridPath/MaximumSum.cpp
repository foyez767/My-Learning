//You will be given a n * n grid , you can move right or down,your task is to calculate a path from (1,1) to (n,n)
//whose sum is as large as possible
//complexity : O(n * n)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100;
int grid[N][N];
int sum[N][N];  

int maxSum(int i, int j){
    if(i == 1 and j == 1){
        return grid[i][j];
    }
    if(i < 1 or j < 1){
        return 0;
    }
    if(sum[i][j] != -1){
        return sum[i][j];
    }

    sum[i][j] = max(maxSum(i - 1, j),maxSum(i, j - 1)) + grid[i][j];

return sum[i][j];
}

void solve(){
    memset(sum , -1, sizeof(sum));
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    cout << maxSum(n, n) << "\n";

 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}

//input: 
/*
5
3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
answer = 67
*/