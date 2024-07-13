#include <bits/stdc++.h>
using namespace std;
#define ll long long int


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// return a random number in [l, r] range
ll rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r)(rng);
}

//generate an array of length n where each element in [l, r] range
vector<int> vec;

void Array(ll n, ll l, ll r) {
	for (int i = 0; i < n; i++) {
		int x = rand(l, r);
		cout << x << (i < n - 1 ? ' ' : '\n');
		vec.push_back(x);
	}
}

void Array2(ll n, ll l, ll r) {
	for (int i = 0; i < n; i++) {
		cout << rand(l, r) << (i < n - 1 ? ' ' : '\n');
	}
}


//generate a string of lowercase letters of length n
void String(int n) {
	for (int i = 0; i < n; i++) {
		cout << (char) ('a' + rand(0, 25));
	}
}

const ll N = 1e12;

int main(int argc, char* argv[]) {
	// randoms numbers will be generated in the output.txt file (in same directory)
	freopen("output.txt", "w", stdout);

	ll testcase = 1;
	// cout << testcase << endl;

	while (testcase--)
	{
		ll n = rand(1500, 1500);
		cout << n << "\n";

		// string s = "abacdxyzrt";
		for (int i = 1; i <= n; i++) {
			String(rand(10, 10));

			if (i < n) {
				cout << " ";
			}
		}

		cout << "\n";

		int l = 1500, r = 1500;

		Array(n, l, r);
		Array2(n, l, r);

		for (int i = 0; i < n; i++) {
			Array(vec[i], -1, 1500);
		}


	}

	return 0;
}
