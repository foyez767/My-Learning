//given n coins, and a value x , minimum no of coins required to produce x and print minimum solution(any)
#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
 
    vector<int> coins(n, 0);
    for(auto &x : coins) cin >> x;

    int value[x + 1]{}, first[x + 1]{}; //first indicates for each sum of money the first coin that can be taken
    // as optimal

    value[0] = 0;   //base case

    for(int i = 1; i <= x; i++){
        value[i] = inf;
        for(auto c : coins){
            if(i - c >= 0 and value[i - c] + 1 < value[i]){
                value[i] = value[i - c] + 1;
                first[i] = c;
            }
        }
    }

    //minimum no of coins required
    if(value[x] >= inf) cout << "-1\n";
    else cout << value[x] << "\n";

    //printing the solution
    while(x > 0){
        cout << first[x] << " ";
        x -= first[x];
    }
    cout << "\n";
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