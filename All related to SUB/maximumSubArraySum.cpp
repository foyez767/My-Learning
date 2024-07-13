//problem : cses
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n; cin >> n;

    int arr[n] {};

    for(int i = 0; i < n; i++) cin >> arr[i];

    int mx_subarray_sum = -1e18, mx_subarray_sum_ending_at_i = -1e18;

    for(int i = 0; i < n; i++) {
        mx_subarray_sum_ending_at_i = max(arr[i], mx_subarray_sum_ending_at_i + arr[i]);
        mx_subarray_sum = max(mx_subarray_sum, mx_subarray_sum_ending_at_i);
    }

    cout  << mx_subarray_sum << "\n";


return 0;
}