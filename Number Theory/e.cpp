//author : Team RUET_AC_Hunters
#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define yes "YES"
#define no "NO"


vector<int> p[1005];
int rankk[1005];
void solve()
{


    int m;
    cin>>m;
    vector< pair<int,int> > vec(m);
    for(int i=0;i<m;i++) {
        cin>>vec[i].first;
        vec[i].second=i+1;
    }
    sort(vec.rbegin(),vec.rend());
    // for(auto v: vec){
    //     cout<< v.first<<" : "<<v.second<<nn;
    // }
    for(ll i=0;i<m;i++) {
        rankk[vec[i].second]=i+1;
    }
    // for(ll i=1; i<=m; i++)
    //     cout<< rankk[i]<<" ";

    ll x=0;
    map<ll,vector<ll>>mp;
    for(ll i=1;i<=m; i++)
    {
        for(ll j=1;j<=m;j++){
            cin>> x;
            mp[i].push_back(x);
        }

    }
    bool mark[m+1]{false};
    ll given[m+1]{};
    ll y=0,flag=0;

    for(ll i=1; i<=m; i++)
    {
        x=rankk[i];
        for(auto m: mp[x]){
            y=m;
            if(mark[y]==false){
                mark[y]=true;
                given[x]=y;
                break;
            }
        }
    }

    for(ll i=1; i<=m; i++)
    {
        cout<< given[i]<<nn;
    }

   }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t;  cin>>t;  for(int i=1;i<=t;i++)
    {
        solve();
    }

    return 0;
}