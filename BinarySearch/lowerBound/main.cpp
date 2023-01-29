//built in lower bound returns the lowest index where you can insert x by keeping your container sorted
//built in upper bound returns the highest index where you can insert x by keeping your container sorted
//they don't care if your x is there or not

//Our own function lower bound returns the index at where  x occured for the first time
//our own function upper bound returns the index at where x occured for the last time
//if x is not there ,then they return -1
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>vec,int key){
    int s=0,e=vec.size()-1,mid=0,ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(vec[mid]==key){
            ans=mid;
            e=mid-1;
        }else if(vec[mid]>key) e=mid-1;
        else s=mid+1;
    }
return ans;
}

int upperBound(vector<int>vec,int key){
    int s=0,e=vec.size()-1,mid=0,ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(vec[mid]==key){
            ans=mid;
            s=mid+1;
        }else if(vec[mid]>key) e=mid-1;
        else s=mid+1;
    }
return ans;
}
int main(){
    vector<int> vec {0,1,1,1,2,2,2,2,3,3,4,6};
    
    cout<< lowerBound(vec,2) <<endl;
    cout << lower_bound(vec.begin(),vec.end(),2)-vec.begin() <<endl;
    cout<<upperBound(vec,2)<<endl;
    cout<< upper_bound(vec.begin(),vec.end(),2) - vec.begin() <<endl;

    return 0;
}