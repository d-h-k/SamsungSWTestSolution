#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int lab[8][8];
int ans;
int cpy[8][8];

typedef pair<int, int> P;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

void print()
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
            cout << lab[i][j] << ' ';
        cout << '\n';
    }
}
bool inMap(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs()
{
    int ret = 0;
    
    queue<P> q;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cpy[i][j] = lab[i][j];
            if(cpy[i][j] == 2)
            {
                q.push(P(i,j));
            }
        }
    }
    
    while(!q.empty())
    {
        P now = q.front();
        q.pop();
        
        for(int d = 0; d < 4; ++d)
        {
            int ny = now.first + dy[d];
            int nx = now.second + dx[d];
            
            if(inMap(ny, nx) && cpy[ny][nx] == 0)
            {
                cpy[ny][nx] = 2;
                q.push(P(ny,nx));
            }
        }
    }
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0 ; j < M; ++j)
        {
          // cout << cpy[i][j] << ' ';
            if(cpy[i][j] == 0)
                ++ret;
        }
       // cout << '\n';
    }
    //cout << "\n\n";
    return ret;
}
// y: 가장 최근에 벽을 놓은 y 좌표
// x: 가장 최근에 벽을 놓은 x 좌표
// wall: 벽의 개수
void dfs(int y, int x, int wall)
{
    lab[y][x] = 3;
    //cout << y << ' ' << x << ' ' << wall << endl;
    //print();
    //cout << '\n';
    if (wall == 3)
    {
        ans = max(ans, bfs());
    }
    else
    {
        for(int i = y; i < N; ++i)
        {
            int st = ((i==y) ? x+1 : 0);
            for(int j = st; j < M; ++j)
            {
                if(lab[i][j] == 0)
                    dfs(i, j, wall+1);
            }
        }
    }
    lab[y][x] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> lab[i][j];
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(lab[i][j] == 0)
            {
                dfs(i, j, 1);
            }
        }
    }
    
    cout << ans;
    return 0;
}
