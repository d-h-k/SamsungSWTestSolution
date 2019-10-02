#include <bits/stdc++.h>
using namespace std;

string gears[4];
int p[4]; 

int f(int n) {
	return (n+8)%8;
}

void query(int n, int d) {
	int dir[] = {0,0,0,0};

	dir[n] = d;
	int tmp = d;
	for (int i = n; i < 3; i++) {
		if(gears[i][f(p[i]+2)] != gears[i+1][f(p[i+1]-2)]) {
			d *= -1;
			dir[i+1] = d;
		} 
		else break;
	}
	d = tmp;
	for (int i = n; i > 0; i--) {
		if(gears[i][f(p[i]-2)] != gears[i-1][f(p[i-1]+2)]) {
			d *= -1;
			dir[i-1] = d;
		} 
		else break;
	}

	for(int i = 0; i < 4; i++)
		p[i] = f(p[i]-dir[i]);
} 

int calc() {
	int ret = 0;
	for(int i = 0; i < 4; i++)  {
		ret += (gears[i][p[i]] - '0') << i;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 0; i < 4; i++) 
		cin >> gears[i];

	int K; cin >> K;
	while(K--) {
		int num, dir;
		cin >> num >> dir;
		query(num-1, dir);
	}

	cout << calc();
	return 0;
}