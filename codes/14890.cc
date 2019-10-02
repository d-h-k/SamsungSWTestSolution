#include <bits/stdc++.h>
using namespace std;

int N, L;
int b[100][100];
int check(int line_num, int is_garo) {
	int ret = 1;

	int prev = -1;
	int a[100] = {0}

	;
	for (int i = 0; i < N; i++) {
		int block = b[is_garo ? line_num : i][is_garo ? i : line_num];
		if (prev == -1) {
			prev = block;
			continue;
		}
		
		int diff = abs(block - prev);

		if (diff > 1) {
			return 0;
		}
		if (diff == 1) {
			if (prev > block) {
				if (i + L - 1 < N) {
					for (int p = i; p < i + L; p++) {
						if (a[p] != 0) 
							return 0;
						a[p] = 1;
						if (b[is_garo ? line_num : p][is_garo ? p : line_num] != block) 
							return 0;
					}
				}
				else return 0;
			} else {
				if (i - L >= 0) {
					for (int p = i - 1; p > i - 1 - L; p--) {
						if (a[p] != 0)
							return 0;
						a[p] = 1;
						if (b[is_garo ? line_num : p][is_garo ? p : line_num] != prev)
							return 0;
					}
				} else return 0;
			}
		}
		prev = block;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N ; i++)
		for (int j = 0; j < N; j++)
			cin >> b[i][j];

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += check(i,0) + check(i, 1);

	cout << ans;
	return 0;
}