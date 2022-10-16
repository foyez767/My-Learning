//Complexity of this algorithm is : O(n)
#include<bits/stdc++.h>
using namespace std;

// This function used to determine if there is a suffix which is equal to any prefix
vector<int> prefix_function(string pattern){
    long long  n=pattern.length();
    vector<int> phi(n,0);

    for(int i=1; i<n; i++){
        int j=phi[i-1];

        while(pattern[i]!=pattern[j] and j>0){
            j=phi[j-1];
        }

        if(pattern[i]==pattern[j])
            j++;
        phi[i] = j;
    }
    return phi;
}

int main(){
    string text="ABCXABCXABCDXABCDABXABCDABCABC";
    string pattern="ABCDABCABC";
    vector<int>phi = prefix_function(pattern);

    int pat_index=-1;
    int i=0,j=0;
    while(i<text.size()){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else {
            if(j!=0)
                j= phi[j-1];
            else i++;
        }
        if(j==pattern.size()){
            pat_index=i-pattern.size();
            break;
        }
    }
    cout<< pat_index <<endl;

    return 0;
}