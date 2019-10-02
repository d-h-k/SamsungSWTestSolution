#include <iostream>
#include <algorithm>
using namespace std;

int T[16];
int P[16];
int d[16]; 
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t, p;
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		d[i] = d[i - 1];
		for (int j = 1; j <= 5; ++j)
		{
			if (i - j >= 0 && T[i - j + 1] == j)
			{
				d[i] = max(d[i], d[i - j] + P[i - j + 1]);
			}
		}
	}

	cout << d[N];
	return 0;
}