//what if a=10^17,b=10^17,m=10^18?
//then if we  apply modular multiplication rules,it won't work ,since (a mod m)*(b mod m) will be overflowed
//to solve this,follow below code
// C++ program of finding modulo multiplication
#include <bits/stdc++.h>
 
using namespace std;
 
// Returns (a * b) % mod
long long moduloMultiplication(long long a, long long b,
                               long long m)
{
    long long res = 0; // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= m;
 
    while (b) {
        // If b is odd, add a with result
        if (b % 2)
            res = (res + a) % m;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % m;
 
        b >>= 1; // b = b / 2//**b=b>>1 means b=b/2^1
    }
 
    return res;
}
 
// Driver program
int main()
{
    long long a = 100000000000000000;
    long long b = 100000000000000000;
    long long m = 1000000000000000000;
    cout << moduloMultiplication(a, b, m);
    return 0;
}
 
// This code is contributed
// by Akanksha Rai