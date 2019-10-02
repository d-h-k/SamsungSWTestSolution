#include <bits/stdc++.h>
using namespace std;

int N, b_sum, ans;
int b[20][20];
void dfs(int depth) {
	if (depth == 5 || ans * 2 > b_sum) return;

	int c[20][20], mx;
	bool changed;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = b[i][j];
			b[i][j] = 0;
		}
	}

	// up
	for (int x = 0; x < N; x++) {
		int pt = 0;
		for (int y = 0; y < N; y++) {
			int block = c[y][x];
			if (block == 0) continue;

			if (b[pt][x] == block) b[pt++][x] <<= 1;
			else if (b[pt][x] == 0) b[pt][x] = block;
			else b[++pt][x] = block;
		}
	}

	changed= false;
	mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] != b[i][j]) changed = true;
			mx = max(mx, b[i][j]);
		}
	}

	ans = max(ans, mx);
	if (changed && ans < (mx<<(4-depth))) {
		dfs(depth+1);
	}

	// down
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			b[i][j] = 0;

	for (int x = 0; x < N; x++) {
		int pt = N - 1;
		for (int y = N - 1; y >= 0; y--) {
			int block = c[y][x];
			if (block == 0) continue;

			if (b[pt][x] == block) b[pt--][x] <<= 1;
			else if (b[pt][x] == 0) b[pt][x] = block;
			else b[--pt][x] = block;
		}
	}

	changed= false;
	mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] != b[i][j]) changed = true;
			mx = max(mx, b[i][j]);
		}
	}

	ans = max(ans, mx);
	if (changed && ans < (mx<<(4-depth))) {
		dfs(depth+1);
	}

	// left
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			b[i][j] = 0;

	for (int y = 0; y < N; y++) {
		int pt = 0;
		for (int x = 0; x < N; x++) {
			int block = c[y][x];
			if (block == 0) continue;

			if (b[y][pt] == block) b[y][pt++] <<= 1;
			else if (b[y][pt] == 0) b[y][pt] = block;
			else b[y][++pt] = block;
		}
	}

	changed= false;
	mx = 0;
	//cout << depth << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] != b[i][j]) changed = true;
			mx = max(mx, b[i][j]);
		}
	}

	ans = max(ans, mx);
	if (changed && ans < (mx<<(4-depth))) {
		dfs(depth+1);
	}

	// right
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			b[i][j] = 0;

	for (int y = 0; y < N; y++) {
		int pt = N - 1;
		for (int x = N - 1; x >= 0; x--) {
			int block = c[y][x];
			if (block == 0) continue;

			if (b[y][pt] == block) b[y][pt--] <<= 1;
			else if (b[y][pt] == 0) b[y][pt] = block;
			else b[y][--pt] = block;
		}
	}

	changed= false;
	mx = 0;
	//cout << depth << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] != b[i][j]) changed = true;
			mx = max(mx, b[i][j]);
		}
	}

	ans = max(ans, mx);
	if (changed && ans < (mx<<(4-depth))) {
		dfs(depth+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> b[i][j];
			b_sum +=b[i][j];
			ans = max(ans, b[i][j]);
		}
	}

	dfs(0);
	cout << ans;
	return 0;
}