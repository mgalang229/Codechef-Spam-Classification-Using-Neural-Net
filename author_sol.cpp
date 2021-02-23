#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, min_x, max_x;
		cin >> n >> min_x >> max_x;
		vector<int> w(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i] >> b[i];
		}
		vector<int> val(2);
		for (int x = 0; x <= 1; x++) {
			int res = x;
			for (int i = 0; i < n; i++) {
				res = ((res * w[i]) + b[i]) % 2;
			}
			val[x] = res;
		}
		int even = 0;
		// assume the values are non-negative
		if (val[min_x % 2] == 0) {
			// this is the formula for getting the number of even numbers between a certain range
			even += (max_x - min_x) / 2 + 1;
		}
		if (val[(min_x + 1) % 2] == 0) {
			// view the image in this repository for derivation of this formula
			even += (max_x - min_x - 1) / 2 + 1;
		}
		// to find the odd number, calculate the difference between the number of elements in a certain range
		// from the number of even values calculated above
		int odd = max_x - min_x + 1 - even;
		cout << even << " " << odd << '\n';
	}
	return 0;
}
