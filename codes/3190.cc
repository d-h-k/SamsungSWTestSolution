#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n,k,l,ans;
int arr[101][101];

typedef pair<int, int> P;
deque<P>snake;
queue<P>cmd;

int main()
{
    int headx = 0, heady = 0;
    int d = 0;
    scanf("%d %d", &n,&k);
    for (int i = 0; i < k; ++i)
    {
        int y,x;
        scanf("%d %d", &y, &x);
        arr[y-1][x-1] = 2;
    }
    snake.push_back(P(0, 0));
    scanf("%d", &l);
    for (int i = 0; i < l; ++i)
    {
        int a;
        char t;
        scanf(" %d %c", &a, &t);
        cmd.push(P(a, t =='D' ? 1 : -1));
    }
    while (++ans)
    {
        heady += dy[d];
        headx += dx[d];
        if (heady < 0 || heady >=n|| headx < 0 || headx >=n ||arr[heady][headx] == 1)
        {
            printf("%d\n", ans);
            return 0;
        }
        else if (arr[heady][headx] == 0)
        {
            arr[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        snake.push_front(P(heady, headx));
        arr[heady][headx] = 1;
        
        if (!cmd.empty()&& ans == cmd.front().first)
        {
            d = (d+cmd.front().second + 4)%4;
            cmd.pop();
        }
    }
}
