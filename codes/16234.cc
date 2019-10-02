#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int b[50][50];

int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};


typedef pair<int,int> P;

bool visited[50][50] = {0};
vector<P> v;
int sum;
bool isIn(int y, int x) { return y>=0&&y<N&&x>=0&&x<N; }
void dfs(P now) {
	for (int d = 0; d < 4; d++) {
		int ny = now.first + dy[d];
		int nx = now.second + dx[d];
		int ingu = b[now.first][now.second];
		if(isIn(ny, nx) && !visited[ny][nx]) {
			int diff = abs(ingu-b[ny][nx]);
			if (L<= diff && diff <= R) {
				visited[ny][nx] = true;
				sum += b[ny][nx];
				v.push_back({ny,nx});
				dfs({ny,nx});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> b[i][j];
		}
	}

	int ans = 0;
	while (true) {
		// visited 초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			 	visited[i][j] = false;

		bool changed = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					sum = b[i][j];
					visited[i][j] = true;
					v.push_back({i,j});
					dfs({i,j});

 					int sz = (int)v.size();
					if (sz >= 2) changed = true;
					for (P p : v) {
						b[p.first][p.second] = sum/sz;
					}
				}
			}
		}
		//cout << "hi" << '\n';

		if (!changed) break;
		++ans;
	}
	cout << ans;
	return 0;
}