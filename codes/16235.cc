#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)

int N, M, K;
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};

struct tree_t {
	int age;
	bool isDie;
	bool operator < (const tree_t& other) {
		return age < other.age;
	}
};

int m[11][11];
vector<tree_t> forest[11][11];
int A[11][11];

bool isIn (int y, int x) { return y>0&&y<=N&&x>0&&x<=N;}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	while (M--) {
		int x, y, z; cin >> x >> y >> z;
		forest[x][y].push_back({z,false});
	}
}

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(forest[i][j].begin(), forest[i][j].end());
			for (auto &t : forest[i][j]) {
				if (t.age > m[i][j]) {
					t.isDie = true;
				} else {
					m[i][j] -= t.age;
					t.age++;
				}
			}
		}
	}
}

void summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto it = forest[i][j].begin(); it != forest[i][j].end();) {
				if (it->isDie) {
					m[i][j] += it->age / 2;
					it = forest[i][j].erase(it);
				} else {
					it++;
				}
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto t : forest[i][j]) {
				if (t.age % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int r = i + dy[d];
						int c = j + dx[d];

						if (!isIn(r, c)) continue;

						forest[r][c].push_back({1,false});
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			m[i][j] += A[i][j];
		}
	}
}

int solve() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ret += forest[i][j].size();
		}
	}
	return ret;
}

int main() {
	solarmagic;

	for (int i = 1; i <= 10; i++) 
		for (int j = 1; j <= 10; j++) 
			m[i][j] = 5;
	input();
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << solve();
	return 0;
}