#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string>subset;

void generate_subset(string s,long long num){
    long long j=0;
    string st;
    while(num>0){
        int last_bit=num & 1;
        if(last_bit==1) 
            st+=s[j];
        j++;
        num = num >> 1;
    }
    subset.push_back(st);
    st.clear();
}

int main(){
    string s;
    cin>>s;
    long long n=s.size();
    for(long long i=0; i<(1<<n); i++){  //pow(2,n)==1<<n
        generate_subset(s,i);
    }

    for(auto sub:subset)
        cout<<sub<<endl;

    return 0;
}