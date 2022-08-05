//subset generation using backtracking and recursion
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets;

void generate_subset(vector<int> &subset,int i,vector<int>&elements){
    //base case
    if(i==elements.size()){
        subsets.push_back(subset);
        return ;
    }
    //if ith element is not included
    generate_subset(subset,i+1,elements);
    //if ith element is included
    subset.push_back(elements[i]);
    generate_subset(subset,i+1,elements);
    subset.pop_back();  //BackTracking
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0,x=0;
    cin>>n;
    vector<int> subset;
    vector<int> elements;
    for(int i=0;i<n;i++){
        cin>>x;
        elements.push_back(x);
    }
    generate_subset(subset,0,elements); //i=0 at first since we need to begin with index 0th element
    //output
    for(auto subset:subsets){
        cout<<"[";
        for(auto ele:subset)
            cout<<ele<<" ";
        cout<<"]\n";
    }
   
    return 0;
}