#include <iostream>

using namespace std;

int place[51][51];
//북 서 남 동
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    int r, c, d; //0북쪽, 1동쪽, 2남쪽, 3서쪽
    cin >> r >> c >> d;
    
    if(d==3) d = 1;
    else if(d==1) d = 3;
    
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> place[i][j];
        }
    }
    
    int ans = 0;
    while(true)
    {
        if(place[r][c] == 0)
        {
            ++ans;
            place[r][c] = 2;
        }
        
        bool escape = false;
        for(int i = 0; i < 4; ++ i)
        {
            if(place[r + dy[(d+1)%4]][c + dx[(d+1)%4]] == 0)
            {
                d = (d+1)%4;
                r = r+dy[d];
                c = c+dx[d];
                escape = true;
                break;
            }
            d = (d+1)%4;
        }
        if(!escape)
        {
            d = (d+2)%4;
            if(place[r+dy[d]][c+dx[d]] != 1)
            {
                r = r + dy[d];
                c = c + dx[d];
            }
            else
            {
                break;
            }
            d = (d+2)%4;
        }
    }
    
    cout << ans;
    return 0;
}
