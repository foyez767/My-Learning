//there are 2n+2 numbers where n numbers are repeated for 2 times,and 2 unique numbers are present
//find out those 2 unique numbers
//sample input: 1 2 3 4 2 1
//sample output: 3,4
#include<iostream>
#include<vector>
using namespace std;

int positionOf_set_bit(int xr){
    int pos=0;
    while(xr&1 == 0){
        pos++;
        xr= xr>>1;
    }

    return pos;
}

int main(){
    int arr[]={1,2,3,4,5,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    int xr=0;
    //xr of all numbers
    for(int i=0;i<n;i++)
        xr=xr^arr[i];

    int pos = positionOf_set_bit(xr);
    //filter out the numbers from array which has set bits at positon= 'pos'
    vector<int>vec;
    int mask=1<<pos;
    for(int i=0;i<n;i++){
        if(arr[i] & mask )
            vec.push_back(arr[i]);
    }

    int unique_1=0;
    for(int i=0;i<vec.size();i++){
        unique_1=unique_1^vec[i];
    }

    int unique_2=unique_1^xr;

    cout<<unique_1<<" "<<unique_2<<endl;

    return 0;
}