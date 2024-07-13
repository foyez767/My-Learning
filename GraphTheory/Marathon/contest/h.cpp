#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string num = "10200"; int k = 1;
    stack<char> st;

        for (int i = 0; i < num.length(); i++) {
            if (st.empty()) {
                st.push(num[i]);
            } else if (!st.empty() and st.top() > num[i] and k > 0) {
                while (!st.empty() and k > 0) {
                    if (st.top() > num[i]) {
                        st.pop();
                        k--;
                    } else {
                        break;
                    }
                }
                st.push(num[i]);
            } else {
                st.push(num[i]);
            }
        }

        for (int i = 1; i <= k; i++) st.pop();

        string s = "";

        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                s.erase(i, 1);
                i--;
            }
        }



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