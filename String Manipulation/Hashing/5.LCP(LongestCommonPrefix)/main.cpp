//given two strings, you need to answer length of the longest common prefix
//complexity: O(N)
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    
    int cnt = 0;

    for(int i = 0; i < a.length(); i++){
        if(a[i] == b[i]){
            cnt++;
        }
        else{
            break;
        }
    }

    cout << cnt << "\n";
return 0;
}

/*
ababaabc
abc
*/