#include <bits/stdc++.h>
using namespace std;

int b[20][20];

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};
struct P{
	int y;
	int x;
};

bool operator < (P a, P b) {
	if (a.y == b.y) return a.x > b.x;
	return a.y > b.y;
}

int sharks[9];
int sz = 2, eaten;
int N; 
bool isIn(int y, int x) { return y>=0&&y<N&&x>=0&&x<N; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	P baby;
	int shark_cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> b[i][j];
			if (b[i][j] == 9) {
				b[i][j] = 0;
				baby = {i, j};
			} else if (b[i][j] > 0) {
				sharks[b[i][j]]++;
			}
		}
	}

	int ans = 0;
	while(true) {
		bool callMom = true;
		for (int i = sz; i >= 1; i--) 
			if (sharks[i]) callMom = false;

		if(callMom) 
			break;

		priority_queue<P> q;
		q.push(baby);
		int cnt = 0;
		bool flag =false;
		bool visited[20][20] = {0};
		//cout << "baby:" << baby.y << ' ' << baby.x << endl; 
		visited[baby.y][baby.x] = true;
		while (!q.empty()) {
			int qsz = q.size();
			vector<P> nom;
			//cout << "qsize " << qsz << endl;
			for (int i = 0; i < qsz; i++) {
				int y = q.top().y;
				int x = q.top().x;
				//cout << y << ' ' << x << endl;
				q.pop();

				if (b[y][x] < sz && b[y][x] > 0) {
					//cout << "eat: " << y << ' ' << x << endl;
					sharks[b[y][x]]--;
					b[y][x] = 0;
					baby = {y, x};
					flag = true;
					break;

				}

				for (int d = 0; d < 4; d++) {
					int ny = y + dy[d];
					int nx = x + dx[d];

					if (isIn(ny, nx) && !visited[ny][nx] && sz >= b[ny][nx]) {
						visited[ny][nx] = true;
						nom.push_back({ny,nx});
						//q.push({ny,nx});
					}
				}
			}
			if(flag) break;
			cnt++;
			for (auto n : nom) {
				q.push(n);
			}
		}	
		if(!flag) {
			break;
		}
		ans +=cnt;
		eaten++;
		if(eaten == sz) {
			sz++;
			eaten = 0;
		}
		//cout << "ans: "<< ans << '\n';
	}
	cout << ans;
	return 0;
}