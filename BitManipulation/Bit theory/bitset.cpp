#include<bits/stdc++.h>
using namespace std;

int main(){
    // declaration
    // 1.
    // bitset< 32 >bset;    //all bits are 0
    // 2.bset hold binary representation of 5 in 32 bit
    // bitset< 32 > bset(5);
    // cout << bset <<endl;
    // step:3 ->
    // bitset< 32 >bset(string("101"));
    // cout<< bset <<endl;
    // cout<< bset.to_ullong() <<endl;

    // ******//
    // bitset< 32 >bset;
    // bset.set();         //set all bits 1
    // cout<< bset <<endl;
    // bset.reset();       //set all bits to 0
    // cout<< bset <<endl;

    // ******counting set bits
    // bitset< 32 >bset(10);
    // cout << bset.count() <<endl;    //count how many bits are set/1 in binary  representation of 10
    
    // ***flip : 0 to 1 ,1 to 0
    // bitset< 32 >bset(10);
    // cout<< bset <<endl;
    // bset.flip();
    // cout<< bset <<endl;

    // ***indexing from right to left,start with 0 indexing
    // bitset<32> bset(10);
    // cout<< bset <<endl;
    // cout<< bset[0] <<endl;
    // cout<< bset[1] <<endl;
    // cout<< bset[2] <<endl;

    // ***2 dimension
    vector<bitset<4>>vec {4,2,1,5,8,9};
    for(int i=0 ;i<vec.size(); i++){
        for(int j=3; j>=0; j--)
            cout<<vec[i][j]<<" ";
        cout<<endl;

    }



    return 0;
}