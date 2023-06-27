//given a string, you need to find the length of longest palindrome
//also print the largest palindrome
//complexity: O(N * logN)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 7;
const int P1 = 137, P2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int power(long long n,long long k, int mod){
    int ans = 1 % mod; n %= mod; if(n < 0) n += mod;

    while(k){
        if(k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
return ans;
}

int invp1, invp2;
pair<int,int> pw[N], invpw[N];

void precal(){
    pw[0] = {1, 1};
 
    for(int i = 1; i < N; i++){
        pw[i].first  = 1LL * pw[i - 1].first * P1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * P2 % mod2;
    }

    invp1 = power(P1, mod1 - 2, mod1);
    invp2 = power(P2, mod2 - 2, mod2);

    invpw[0] = {1, 1};

    for(int i = 1; i < N; i++){
        invpw[i].first = 1LL * invpw[i - 1].first * invp1 % mod1;
        invpw[i].second = 1LL * invpw[i - 1].second * invp2 % mod2;
    }
}

class Hash{
    public:
    pair<int,int> pref[N];

    void build(string s){
    int n = s.size();

    for(int i = 0; i < n; i++){
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
        }
    }

    //substring hash
    pair<int,int> getHash(int i, int j){
        assert(i <= j);
        pair<int,int> hs = {0, 0};

        hs.first = pref[j].first;
        if(i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
        hs.first = 1LL * hs.first * invpw[i].first % mod1;

        hs.second = pref[j].second;
        if(i) hs.second = (hs.second - pref[i -1].second + mod2) % mod2;
        hs.second = 1LL * hs.second * invpw[i].second % mod2;
    return hs;
    }

    //hash of a string
    pair<int,int> stringHash(string s){
        int n = s.size();
 
        pair<int,int> hs = {0, 0};
 
        for(int i = 0; i < n; i++){
            hs.first += 1LL * s[i] * pw[i].first % mod1;
            hs.second += 1LL * s[i] * pw[i].second % mod2;
            hs.first %= mod1;
            hs.second %= mod2;
        }
    return hs;
    }

}ts, tr;

int n;

bool isPalindrome(int len){
    for(int i = 0; i + len - 1 < n; i++){
        if(ts.getHash(i, i + len - 1) == tr.getHash(n - i - len , n - i - 1)){  //[l,r - 1] == [n - r - 1, n - l - 1]
            return true;
        }
    }
return false;
}

void solve(){
    precal();

    string s; cin >> s;
    n = s.length();
    string st = s;
    reverse(st.begin(), st.end());
 
    ts.build(s);
    tr.build(st);
//odd length: minLength = 1, maxLength = n hence ekpashe maximum thakbe (n + 1) / 2 oporpashe n / 2
    int lo = 1, hi = (n + 1) / 2, ans1 = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(isPalindrome(2 * mid - 1)){
            ans1 = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

//even length palindrome
    lo = 1, hi = n / 2; //**** lo = 1[remember it]
    int ans2 = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(isPalindrome(2 * mid)) {
            ans2 = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int lenP =  max(2 * ans1 - 1, 2 * ans2) ;   //length of longest palindrome

    for(int i = 0; i + lenP - 1 < n; i++){
        if(ts.getHash(i, i + lenP - 1) == tr.getHash(n - i - lenP, n - i - 1)) {
            cout << s.substr(i, lenP) << "\n";
            return;
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