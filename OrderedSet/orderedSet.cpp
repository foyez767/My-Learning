//it is like stl set but we can access certain indexed value at logN time
//0 based indexing
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  o_set<int> se;
  se.insert(4);
  se.insert(5);
  se.insert(2);
  se.insert(2);
  se.insert(9);

  cout << *(se.find_by_order(0)) << endl;   // what is in index 0
  cout << *se.find_by_order(1) << endl;     // what is in index 1
  cout << se.order_of_key(5) << endl;       // how many elements strictly less than 5
  cout << se.order_of_key(9) << endl;       // how many elements strictly less than 9

  return 0;
}