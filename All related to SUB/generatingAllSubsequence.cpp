#include<bits/stdc++.h>
using namespace std;

const int N = 24;
int n, arr[N];
bool isTaken[N];

void  rec(int i) {
    if(i > n) {
        for(int i = 1; i <= n; i++) {
            if(isTaken[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    //don't take ith item
    isTaken[i] = false;
    rec(i + 1);

    //take ith item
    isTaken[i] = true;
    rec(i + 1);
}


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    rec(1);

return 0;
}