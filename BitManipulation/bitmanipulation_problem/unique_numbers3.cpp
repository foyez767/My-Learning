//there are 3n+1 numbers means n numbers are repeated for 3 times,we need to find out the unique one
//sample input: 1,2,3,4,1,2,3,2,3,1
//sample output: 4
//this technique is also applicable for : 5n+1 ,7n+1 and so on
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int arr[]={1,2,3,3,2,1,4,1,3,2,4,4,100,1002,1111,1111,100,100,1111};
    int n=sizeof(arr)/sizeof(arr[0]);

    int sumArr[32] {};

    for(int i=0; i<n; i++){
        for(int j=0; j<32; j++){
            int ith_bit= arr[i] & (1<<j);
            if(ith_bit)
                sumArr[j]++;
        }
    }

    for(int i=0;i<32;i++)
        sumArr[i] %= 3;

    int unique=0;
    for(int i=0;i<32;i++){
        unique+= (sumArr[i]*pow(2,i));
    }
    cout<<unique<<endl;
    

    return 0;
}
