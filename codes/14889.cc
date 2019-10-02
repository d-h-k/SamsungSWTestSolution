#include <bits/stdc++.h>
using namespace std;

int N;
int adj[30][30];

int ans = INT_MAX;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];


	int sz = (1 << N);
	for (int i = 0; i < sz; i++) {
		int zero_sum = 0, one_sum = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if ((i & (1 << j)) && (i & (1 << k))){
					one_sum += adj[j][k];
				} 
				else if (!(i & (1 << j)) && !(i & (1 << k))) {
					zero_sum += adj[j][k];
				}
			}
		}
		int diff = abs(zero_sum - one_sum);
		ans = min(ans, diff);
	}
	cout << ans;
	return 0;
}