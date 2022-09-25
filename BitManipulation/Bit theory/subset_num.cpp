#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>subset;

void generate_subset(int arr[],int num){
    int j=0;
    vector<int> sub;
    while(num>0){
        int last_bit= num & 1;
        if(last_bit==1)
            sub.push_back(arr[j]);
        j++;
        num= num >> 1;
    }
    subset.push_back(sub);
    sub.clear();
}

int main(){
    int arr[]={ 1, 2, 3, 4};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i< (1<<n); i++){
        generate_subset(arr,i);
    }
    //output
    for(auto v:subset){
        cout<<"[ ";
        for(auto s_set: v)
            cout<<s_set<<" ";
        cout<<"]"<<endl;
    }

    return 0;
}