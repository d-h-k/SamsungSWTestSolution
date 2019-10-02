#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[500][500];
int ans;

struct P{
	int y;
	int x;
	P(int a, int b) : y(a), x(b) {}
};

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int ss[][3][2] = {
	{{-1,-1},{-1,0},{-1,1}}, 
	{{-1,-1},{0,-1},{1,-1}},
	{{1,1},{0,1},{-1,1}},
	{{1,-1},{1,0},{1,1}},
};

bool isIn(int y , int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int val(int y, int x, int rem, vector<P> prev) {
	int ret = 0;
	if (rem == 0) return 0;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (!isIn(ny, nx)) continue;

		bool isPrev = false;
		for (auto p : prev) {
			if(p.y == ny && p.x == nx)
				isPrev = true;
		}

		if(isPrev) continue;
		prev.push_back(P(ny,nx));
		ret = max(ret, board[ny][nx] + val(ny, nx, rem - 1, prev));
		prev.pop_back();
	}
	return ret;
}

int go(int sy, int sx) {
	vector<P> prev;
	prev.push_back(P(sy,sx));
	return board[sy][sx] + val(sy, sx, 3, prev);
}


int go2(int sy, int sx) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int three = 0;
		for (int j = 0; j < 3; j++) {
			int ny = sy + ss[i][j][0];
			int nx = sx + ss[i][j][1];

			if (!isIn(ny, nx)) continue;
			three += board[ny][nx];
		}
		ret = max(ret, board[sy][sx] + three);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			ans = max(ans, go(i, j));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			ans = max(ans, go2(i, j));

	cout << ans;
	return 0;
}