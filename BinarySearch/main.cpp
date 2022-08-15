//complexity: O(logN) **log base 2**
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int no_element=0;
    cin>>no_element;
    vector<int>element(no_element);
    for(int i=0;i<element.size();i++){
        cin>>element[i];
    }
    std::sort(element.begin(),element.end());
    int to_find=0,lo=0,hi=(no_element-1);//as index begin from 0 so high range is (n-1)
    cin>>to_find;   //which one to search
    int mid=0;
    while((hi-lo)>1){
        mid=(hi+lo)/2;
        if(element[mid]<to_find)
            lo=mid+1;
        else
            hi=mid;
    }
    cout<<"Index of "<<to_find<<" is :";
    if(element[lo]==to_find)
        cout<<lo<<endl;
    else if(element[hi]==to_find)
        cout<<hi<<endl;
    else cout<<"NOt found\n";

}