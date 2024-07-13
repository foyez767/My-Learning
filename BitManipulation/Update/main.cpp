#include<bits/stdc++.h>
using namespace std;

//check kth bit is set or not ; indexing start from left : ....3 2 1 0
int check_kth_bit(int x, int k) {
    return ((x >> k) & 1);
}

//print the position of all set bits in binary representation
void print_set_bits(int x) {
    for(int k = 0; k < 32; k++) {
        if((x >> k) & 1) {
            cout << k << " ";
        }
    }
    cout << "\n";
}

//count set bits
int count_set_bits(int x) {
    int cnt = 0;

    for(int k = 0; k < 32; k++) {       //x integer, hence k < 32; if x is long long then k < 64
        if((x >> k) & 1) {
            cnt++;
        }
    }
return cnt;
}

//check a number is even or odd : if last bit is 1 then odd, if last bit is 0 then even
bool is_odd(int x) {
    return (x & 1);
}

//turn ON a bit
int set_kth_bit(int x, int k) {
    return (x | (1 << k));
}

//turn OFf a bit
int unset_kth_bit(int x, int k) {
    return (x & (~(1 << k)));
}

//toggle kth bit
int toggle_kth_bit(int x, int k) {
    return (x ^ (1 << k));
}

//multiply a number by 2
int multiply(int x) {
    return (x << 1);    // x * (1 << 1)
}

//divide a number by 2
int divide(int x) {
    return (x >> 1);
}

//power of 2
int power(int k) {
    return (1 << k);
}

//check power of 2
bool check_power_of2(int x) {
    int cnt = 0;
    for(int k = 0; k < 32; k++) {
        if((x >> k) & 1) {
            cnt++;
        }
    }
    return (cnt == 1) ? true : false;
}

//another way to check a number is power of 2 or not
bool check_power_of_2(int n) {
    return (n & (n - 1) == 0) ? true : false;
}

int main(){
    int x = 13; //binary representation : 1101

    cout << check_kth_bit(x, 2) << "\n";
    
    print_set_bits(x);

    cout << count_set_bits(x) << "\n";

    cout << boolalpha;

    cout << is_odd(10) << " : " << is_odd(11) << "\n";

    cout << set_kth_bit(x, 1) << "\n";
    cout << unset_kth_bit(x, 2) << "\n";

    cout << toggle_kth_bit(x, 2) << "\n";
    cout << toggle_kth_bit(x, 1) << "\n";


    cout << multiply(x) << "\n";
    cout << divide(x) << "\n";

    cout << power(4) << "\n" ; // 2^4 = 16

    cout << check_power_of2(13) << "\n";
    cout << check_power_of2(16) << "\n";
    cout << check_power_of_2(32) << "\n";
    cout << check_power_of_2(4) << "\n";

    cout << (x ^ x ^ x) << endl;
   

return 0;
}