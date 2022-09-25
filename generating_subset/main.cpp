//subset generation using backtracking and recursion
#include<bits/stdc++.h>
using namespace std;

vector<int>elements;    // all value is here
vector<vector<int>>subsets; //every subset is here


void generate_subset(vector<int> &sub,int i){
    //base case
    if(i==elements.size()){
        subsets.push_back(sub);
        return ;
    }
    //if ith element is not included
    generate_subset(sub,i+1);
    //if ith element is included
    sub.push_back(elements[i]);
    generate_subset(sub,i+1);
    sub.pop_back();  //BackTracking
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
  
    int n=0,x=0;
    cin>>n;
    vector<int> sub;
    for(int i=0;i<n;i++){
        cin>>x;
        elements.push_back(x);
    }
    generate_subset(sub,0); //i=0 at first since we need to begin with index 0th element
    //output
    cout<<"[ ";
    for(auto sub:subsets){
        cout<<"[ ";
        for(auto ele:sub)
            cout<<ele<<" ";
        cout<<"]";
    }
    cout<<endl;
   
    return 0;
}