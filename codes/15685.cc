#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> gen;


bool b[102][102];

int dy[] ={0,-1,0,1};
int dx[] ={1,0,-1,0};

void query(int x, int y, int d, int g) {
	b[y][x] = true;
	int ny = y + dy[d];
	int nx = x + dx[d];
	b[ny][nx] = true;

	if (g == 0) return;
	g--;
	for (auto dir : gen[g]) {
		if (dir == 0) {
			d = (d + 1) % 4;
		} else {
			d = (d + 3) % 4;
		}
		ny += dy[d];
		nx += dx[d];
		b[ny][nx] = true;
	}
}



int calc() {
	int ret = 0;
	for (int y = 0; y <= 100; y++) {
		for (int x =0; x<= 100; x++) {
			if (b[y][x] && b[y+1][x] && b[y][x+1] && b[y+1][x+1]) {
				++ret;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<bool> first;
	first.push_back(0);
	gen.push_back(first);
	for (int i = 1; i+1 <= 10; i++) {
		vector<bool> a;
		a.insert(a.end(), gen[i-1].begin(), gen[i-1].end());
		a.push_back(0);
		for (int j = gen[i-1].size() - 1; j >= 0; j--) {
			a.push_back(1-gen[i-1][j]);
		}
		gen.push_back(a);
	}

	int N;
	cin>> N;
	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		query(x, y, d, g);
	}
	cout << calc();

	return 0;
}