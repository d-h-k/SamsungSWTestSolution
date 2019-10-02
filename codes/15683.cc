#include <bits/stdc++.h>
using namespace std;

struct P {
	int y;
	int x;
};

vector<P> cctv;
int dd[9]={1,3,1};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};
int N, M;
int b[9][9];
int sz;
int ans = INT_MAX;

bool isIn(int y, int x) {
	return y >= 0 && y < N && x >=0 && x < M;
}

bool check(int d, int y, int x) {
	int i;
	if (b[y][x] == 5) {
		return true;
	}

	for (i = 0; i < sz; i++) {
		if (cctv[i].y == y && cctv[i].x == x) break;
	}

	int type = b[y][x];
	if (type == 1) {
		return d == dd[i];
	} 
	else if (type == 2) {
		return d == dd[i] || d == (dd[i]+2)%4;
	}
	else if (type == 3) {
		return d == dd[i] || d == (dd[i]+1)%4;
	}
	else return d != dd[i];
}
int calc() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j] != 0) continue;

			bool sagak = true;

			for (int d = 0; d < 4; d++) {
				int k = 1;
				while (true) {
					int ny = i + k* dy[d];
					int nx = j + k* dx[d];
					k++;

					if (!isIn(ny, nx))
						break;

					if (b[ny][nx] == 6)
						break;
					if (b[ny][nx] > 0) {
						if (check(d, ny, nx)) {
							sagak = false;
							break;
						}
					}
				}
			} 

			if (sagak) {
				//cout<< i << ' ' << j << endl;
				ret++;
			}
		}
	}
	return ret;
}
void dfs(int depth) {
	if (depth == sz) {
		ans = min(ans, calc());
		return;
	}

	P now = cctv[depth];
	int type = b[now.y][now.x];
	if (type == 2) {
		dd[depth] = 0;
		dfs(depth+1);
		dd[depth] = 1;
		dfs(depth+1);
	} else {
		for (int i = 0; i < 4; i++) {
			dd[depth] = i;
			dfs(depth+1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
			if (b[i][j] != 0 && b[i][j] != 6 && b[i][j] != 5) {
				cctv.push_back({i,j});
			}
		}
	}
	sz = cctv.size();

	dfs(0);
	//calc();
	cout << ans;
	return 0;
}