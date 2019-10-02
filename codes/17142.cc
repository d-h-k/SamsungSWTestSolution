#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)

struct P {
	int y;
	int x;
};

vector<P> virus;
int b[51][51];
int sz;
int N, M;
int void_cnt;
int ans = INT_MAX;

int dy[] = {0,1,-1,0};
int dx[] = {1,0,0,-1};

bool isIn(int y, int x) { return y>=0&&y<N&&x>=0&&x<N; }
int solve(int vv) {
	int ret = 0;
	queue<P> q;
	bool visited[51][51] = {0};

	for (int i = 0; i < sz; i++) {
		if (vv & (1 << i)) {
			q.push(virus[i]);
			visited[virus[i].y][virus[i].x] = true;
		}
	}

	int cnt = 0;
	while (!q.empty() && cnt != void_cnt) {
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			P now = q.front();
			q.pop();

			for (int d = 0; d < 4; d++) {
				int ny = now.y + dy[d];
				int nx = now.x + dx[d];

				if (isIn(ny,nx) && !visited[ny][nx] && b[ny][nx] != 1) {
					if (b[ny][nx] == 0) ++cnt;
					visited[ny][nx] = true;
					q.push({ny,nx});
				}
			}
		}
		++ret;
	}
	return cnt == void_cnt ? ret : INT_MAX;
}
int main() {
	solarmagic;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> b[i][j];
			if(b[i][j] == 2) 
				virus.push_back({i,j});
			if(b[i][j] == 0) void_cnt++;
		}
	}

	sz = virus.size();
	for (int i = 0; i < (1 << sz); i++) {
		if(__builtin_popcount(i) == M) {
			ans = min(ans, solve(i));
		}
	}

	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}