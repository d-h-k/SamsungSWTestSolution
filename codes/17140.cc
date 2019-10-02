#include <bits/stdc++.h>
using namespace std;

#define solarmagic ios_base::sync_with_stdio(false),cin.tie(nullptr)

int A[101][101];
int rcnt = 3;
int ccnt = 3;
int main() {
	solarmagic;

	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> A[i][j];

	int ans;
	while(true) {
		if (A[r][c] == k) {
			cout << ans;
			return 0;
		}
		if (ans == 100) 
			break;

		if (rcnt>=ccnt) {
			int next = ccnt;
			for (int i = 1; i <= rcnt; i++) {
				int cnt[101] ={0};
				for (int j = 1; j <= ccnt; j++) {
					cnt[A[i][j]]++;
				}
				vector<pair<int,int>> v;
				for (int j = 1; j <= 100; j++) {
					if(cnt[j]) {
						v.push_back({cnt[j],j});
					}
				}
				sort(v.begin(), v.end());

				int sz = v.size();
				int idx = 0;
				for(int j = 0; idx <= 100 && j < sz; j++) {
					A[i][++idx] = v[j].second;
					A[i][++idx] = v[j].first;
				}
				next = max(next, idx);
				for (++idx; idx <= ccnt; idx++) {
					A[i][idx] = 0; 
				}
			}
			ccnt = next;
		} else {
			int next = rcnt;
			for (int i = 1; i <= ccnt; i++) {
				int cnt[101] ={0};
				for (int j = 1; j <= rcnt; j++) {
					cnt[A[j][i]]++;
				}
				vector<pair<int,int>> v;
				for (int j = 1; j <= 100; j++) {
					if(cnt[j]) {
						v.push_back({cnt[j],j});
					}
				}
				sort(v.begin(), v.end());

				int sz = v.size();
				int idx = 0;
				for(int j = 0; idx <= 100 && j < sz; j++) {
					A[++idx][i] = v[j].second;
					A[++idx][i] = v[j].first;
				}
				next = max(next, idx);
				for (++idx; idx <= ccnt; idx++) {
					A[idx][i] = 0; 
				}
			}
			rcnt = next;
		}

		// for (int i = 1; i <= rcnt; i++) {
		// 	for (int j = 1; j <= ccnt; j++) {
		// 		cout << A[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		// cout << endl;

		++ans;
	}
	cout << -1;
	return 0;
}