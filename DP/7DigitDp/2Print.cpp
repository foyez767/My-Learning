//print all numbers from 1 to given value (s)
#include<bits/stdc++.h>
using namespace std;

string s;

void go(int i, bool last, int num){
    if(i == s.size()){
        cout << num << "\n";
        return;
    }
    
    int till = (last) ? (s[i] - '0') : 9 ;

    for(int digits = 0; digits <= till; digits++){
        go(i + 1, (last && (digits == till)),num * 10 + digits);
    }
}

int main(){
    cin >> s;

    go(0, true, 0);

return 0;
}