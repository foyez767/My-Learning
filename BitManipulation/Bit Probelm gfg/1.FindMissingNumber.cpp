//Given an array of (n - 1) integers. All elements is in between [1 to n]. find the missing one
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7;

    int arr[n - 1] = {2, 1, 5, 6, 7, 4};

    int xor_a = 0;

    for(int i = 0; i < n - 1; i++) {
        xor_a = xor_a ^ arr[i];
    }

    int xor_all = 0;

    for(int i = 1; i <= n; i++) {
        xor_all = xor_all ^ i;
    }

    cout << "Missing number is : " << (xor_all ^ xor_a) << "\n";

return 0;
}

/*
Solution Idea :
xor_all = xor of all elements (here each element appears exactly once)
xor_a   = xor of all given elements (here each elements also appears exactly once)

result = (xor_all ^ xor_a)

In result , each elements appears twice except the missing one which is included in xor_all but excluded in xor_a

*/