#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)

int R, C, M;

struct shark_t {
	int s;
	int d;
	int z;
};

shark_t shark[101][101], tmp[101][101];
int ans;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
int main() {
	solarmagic;

	cin>>R>>C>>M;
 
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			shark[i][j] = {0,0,0};
			tmp[i][j] = {0,0,0};
		}
	}
   
	while (M--) {
		int r, c, s, d, z;
		cin>>r>>c>>s>>d>>z;
		if(d<3) s = s%(2*R-2);
		else s = s%(2*C-2);
		shark[r][c] = {s,d-1,z};
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (shark[j][i].z) {
				ans += shark[j][i].z;
				shark[j][i] = {0,0,0};
				break;
			}
		}

		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				if (shark[j][k].z) {
					int s = shark[j][k].s;
					int d = shark[j][k].d;
					int z = shark[j][k].z;
					int ny = j + s*dy[d];
					int nx = k + s*dx[d];

					while (ny <= 0 || ny > R) {
						if (ny <= 0) d = 1, ny = 2 - ny;
						if (ny > R)  d = 0, ny = 2*R-ny;
					}
					while (nx <= 0 || nx > C) {
						if (nx <= 0) d = 2, nx = 2 - nx;
						if (nx > C)  d = 3, nx = 2*C-nx;
					}

					if (tmp[ny][nx].z < z) tmp[ny][nx] = {s,d,z};
					shark[j][k] = {0,0,0};
				}
			}
		}

		for (int j = 1; j<= R; j++) {
			for (int k = 1; k <= C; k++) {
				shark[j][k] = tmp[j][k];
				tmp[j][k] = {0,0,0};
			}
		}
	}
	cout << ans;
	return 0;
}