#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)

int a[51][51];
int b[51][51];
int R, C, T; 
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int rdy[] = {1,0,-1,0};
int rdx[] = {0,1,0,-1};
int yy;
bool isIn(int y, int x) { return y>=0&&y<R&&x>=0&&x<C; }
int main() {
	solarmagic;

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				yy = i;
			}
		}
	}

	while(T--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				b[i][j] = 0;
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (isIn(ny,nx) && a[ny][nx] != -1) {
						++cnt;
					}
				}
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (isIn(ny,nx) && a[ny][nx] != -1) {
						b[ny][nx] += a[i][j]/5;
					}
				}
				a[i][j] -= (a[i][j]/5)*cnt;
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				a[i][j] += b[i][j];
			}
		}
		// 위쪽
		yy--;
		int y = yy - 1, x = 0;
		for (int d = 0; d < 4; d++) {
			while (isIn(y+dy[d],x+dx[d]) && y+dy[d] <= yy) {
				a[y][x] = a[y+dy[d]][x+dx[d]];
				y = y+dy[d];
				x = x+dx[d];
			}
		}
		a[yy][1] = 0;

		// for (int i = 0; i < R; i++) {
		// 	for (int j = 0; j < C; j++) {
		// 		cout << a[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		yy++;
		y = yy + 1, x = 0;
		for (int d = 0; d < 4; d++) {
			while (isIn(y+rdy[d],x+rdx[d]) && y+rdy[d] >= yy) {
				//cout << y << ' ' << x << endl;
				a[y][x] = a[y+rdy[d]][x+rdx[d]];
				y = y+rdy[d];
				x = x+rdx[d];
			}
		}
		a[yy][1] = 0;
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += a[i][j];
		} 
	}
	cout << ans+2;
	return 0;
}