#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int b[40][40];

bool go() {
	vector<int> v;
	for (int i = 0; i <= N; i++) v.push_back(i);

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if(b[i][j]) {
				swap(v[j], v[j+1]);	
			}
		}
	}

	for (int i = 0; i <= N; i++) if(v[i] != i) return false;
	return true;
}

bool dfs(int remain, int sy, int sx) {
	if (remain == 0) return go();

	int ret = false;
	for (int i = sy; i <= H && !ret; i++) {
		for (int j = (i == sy) ? sx+1 : 1; j < N && !ret; j++) {
			if(b[i][j] == 0 && b[i][j-1] == 0 && b[i][j+1] == 0) {
				b[i][j] = 1;
				ret |= dfs(remain - 1, i, j);
				b[i][j] = 0;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> H;
	while (M--) {
		int y, x; cin >> y >> x;
		b[y][x] = 1;
	}

	for (int i = 0; i <= 3; i++) {
		if(dfs(i, 0, 0)) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}