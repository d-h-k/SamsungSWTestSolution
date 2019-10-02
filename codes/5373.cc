#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define cidx idx.first
#define eidx idx.second

struct rubiks{
	vector<string> c, e;
	map<char,pair<vector<int>,vector<int>>> idxes; 

	rubiks() : c{"wrg","wrb","wob","wog","yrg","yrb","yob","yog"},
	e{"wr","wb","wo","wg","rb","ob","og","rg","yr","yb","yo","yg",} {
		idxes['U'] = {{3,2,1,0},{3,2,1,0}};  
		idxes['D'] = {{4,5,6,7},{8,9,10,11}};
		idxes['F'] = {{0,1,5,4},{0,4,8,7}};
		idxes['B'] = {{2,3,7,6},{2,6,10,5}};
		idxes['L'] = {{3,0,4,7},{3,7,11,6}};
		idxes['R'] = {{1,2,6,5},{1,5,9,4}};
	}

	void rotate(char face, char dir) {
		auto idx = idxes[face];

		if (dir == '-') {
			reverse(ALL(cidx));
			reverse(ALL(eidx));
		}

		if (face == 'F' || face == 'B') {
			for (auto& ee : eidx) swap(e[ee][0], e[ee][1]);
			for (auto& cc : cidx) swap(c[cc][0], c[cc][2]);
		}
		if (face == 'R' || face == 'L') {
			for (auto& cc : cidx) swap(c[cc][0], c[cc][1]);
		}
		if (face == 'U' || face == 'D') {
			for (auto& cc : cidx) swap(c[cc][1], c[cc][2]);
		}

		string ctmp = c[cidx[3]], etmp = e[eidx[3]];
		for (int i = 3; i > 0; i--) {
			c[cidx[i]] = c[cidx[i-1]], e[eidx[i]] = e[eidx[i-1]];
		}
		c[cidx[0]] = ctmp, e[eidx[0]] = etmp;
	}

	void print_top() {
		cout<<c[3][0]<<e[2][0]<<c[2][0]<<'\n';
		cout<<e[3][0]<<'w'<<e[1][0]<<'\n';
		cout<<c[0][0]<<e[0][0]<<c[1][0]<<'\n';
	}
};

int main() {
	solarmagic;

	int T; cin >> T;
	while (T--) {
		rubiks cube;
		int n; cin>>n;
		while (n--) {
			string q; cin>>q;
			cube.rotate(q[0],q[1]);
		}
		cube.print_top();
	}
	return 0;
}