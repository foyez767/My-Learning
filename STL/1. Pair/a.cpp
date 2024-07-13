#include<bits/stdc++.h>
using namespace std;

int enemies = 5;

int func () {
    enemies = 8;
    cout << "inside : " << enemies << endl;
}
int main(){
    func();
    
    cout << "outside:  " << enemies << endl;

return 0;
}