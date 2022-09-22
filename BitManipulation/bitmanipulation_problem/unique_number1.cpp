//there are 2n+1 numbers,where n numbers are present twice ,you have to find out the unique one
//sample input: 1 2 5 2 1 
//sample output: 5
//rules: a^a=0,a^a^b or a^b^a=b
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n] {};
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //process
    int uni=0;
    for(int i=0; i<n; i++)
        uni=uni^arr[i];

    cout<<uni<<endl;

    return 0;
}