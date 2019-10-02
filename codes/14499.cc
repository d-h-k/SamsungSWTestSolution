#include <iostream>
using namespace std;

int map[20][20];

//   1
// 3 0 2
//   4
//   5

int dice[7]; 

void change(int y, int x)
{
	if (map[y][x] == 0)
	{
		map[y][x] = dice[6];
	}
	else
	{
		dice[6] = map[y][x];
		map[y][x] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, K;
	cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];

	for (int i = 0; i < K; ++i)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) //동쪽
		{
			if (x == M - 1)
				continue;

			x++;

			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;

			change(y, x);
		}
		if (cmd == 2) //서쪽
		{
			if (x == 0)
				continue;

			x--;

			int tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;

			change(y, x);
		}
		if (cmd == 3) //북쪽
		{
			if (y == 0)
				continue;

			y--;

			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;

			change(y, x);
		}
		if (cmd == 4) //남쪽
		{
			if (y == N - 1)
				continue;

			y++;

			int tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;

			change(y, x);
		}
		
	
		cout << dice[1] << '\n';

	}

	return 0;
}