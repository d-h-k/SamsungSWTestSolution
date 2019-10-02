#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int mn = 2E9;
int mx = -2E9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0 ; i < N; i++) {
		cin >> v[i];
	}

	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	
	vector<char> op;
	for (int i = 0; i < 4; i++)
		op.insert(op.end(), a[i], i+'a');

	do {
		int res = v[0];
		for (int i = 1; i < N; i++) {
			if (op[i-1] == 'a') res += v[i];
			else if (op[i-1] == 'b') res -= v[i];
			else if (op[i-1] == 'c') res *= v[i];
			else res /= v[i];
		}
		mn = min(mn, res);
		mx = max(mx, res);
	} while(next_permutation(op.begin(), op.end()));
	cout << mx << '\n' << mn;
	return 0;
}