#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10;
int dp[N][N], r = 3, c = 3, a[N][N];

int rec (int i, int j) {
  if (i > r) return 0;
  
  if (dp[i][j] != -1) return dp[i][j];


  int ans = 100;

  for (int k = 1; k <= c; k++) {
    if (k != j) {
      ans = min (ans, rec (i + 1, k) + a[i][k]);
    }
  }

  return dp[i][j] = ans;
}


void solve(){
  memset(dp, -1, sizeof(dp));

  int x = 1;

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      a[i][j] = x++;
    }
  }
  // a[1][1] = 7;

  int ans = 1100;
  for (int i = 1; i <= c; i++) {
    ans = min (ans, rec (1, -1));
  }

  cout << ans << endl;
  
 
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++){
    solve();
  }
  
  return 0;
}