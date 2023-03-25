//print all 2 digits numbers
#include<bits/stdc++.h>
using namespace std;

//i = ith digits from left to right , num = current number
void go(int i, int num){
    if(i == 2){
        cout << num << endl;
        return;
    }
    for(int digits = 0; digits <= 9; digits++){
        go(i + 1, num * 10 + digits);
    }
}
int main(){

    go(0, 0);

return 0;
}