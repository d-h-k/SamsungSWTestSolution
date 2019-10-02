#include <cstdio>
#include <vector>
#include <queue>
#define y first
#define x second
using namespace std;
typedef pair<int, int> P;
char board[10][10];

bool check[10][10][10][10];

//왼쪽 오른쪽 아래 위
int dy[]={0,0,1,-1};
int dx[]={-1,1,0,0};
struct S{ P r, b; int cnt; };
int N, M;

bool isValid(int Y, int X) { return Y<N && Y>=0 && X<M && X>=0; }
void print(S s)
{
    printf("ry: %d rx : %d\n", s.r.y, s.r.x);
    printf("by: %d bx : %d\n", s.b.y, s.b.x);
    printf("cnt : %d\n", s.cnt);
}

int main()
{
    P R, B, O;
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            char c;
            scanf(" %c", &c);
            if(c=='R') {R.y=i; R.x=j;}
            if(c=='B') {B.y=i; B.x=j;}
            if(c=='O') {O.y=i; O.x=j;}
            board[i][j]=c;
        }
    }
    
    queue<S> q;
    S tmp;
    tmp.r = R; tmp.b = B; tmp.cnt=0;
    check[R.y][R.x][B.y][B.x]=true;
    q.push(tmp);
    while(!q.empty())
    {
        S now = q.front();
        q.pop();
        
        int ry=now.r.y, rx=now.r.x;
        int by=now.b.y, bx=now.b.x;
        
        if(now.cnt>10)
            continue;
        
        if(by==O.y && bx==O.x)
            continue;
        
        if(ry==O.y && rx==O.x)
            return !printf("%d", now.cnt);
        
        for(int d=0; d<4; ++d)
        {
            while(isValid(ry, rx))
            {
                ry = ry + dy[d];
                rx = rx + dx[d];
                if(board[ry][rx]=='O')
                {
                    break;
                }
                if(board[ry][rx]=='#')
                {
                    ry = ry - dy[d];
                    rx = rx - dx[d];
                    break;
                }
            }
            
            while(isValid(by, bx))
            {
                by = by + dy[d];
                bx = bx + dx[d];
                if(board[by][bx]=='O')
                {
                    break;
                }
                if(board[by][bx]=='#')
                {
                    by = by - dy[d];
                    bx = bx - dx[d];
                    break;
                }
            }

            if(ry==by && rx==bx && board[ry][rx]!='O')
            {
                if(d==0)
                {
                    if(now.r.x<now.b.x) bx++;
                    else rx++;
                }
                
                if(d==1)
                {
                    if(now.r.x<now.b.x) rx--;
                    else bx--;
                }
                
                if(d==2)
                {
                    if(now.r.y<now.b.y) ry--;
                    else by--;
                }
                
                if(d==3)
                {
                    if(now.r.y<now.b.y) by++;
                    else ry++;
                }
            }
            
            //printf("t: %d %d %d %d\n", ry, rx, by, bx);
            if(!check[ry][rx][by][bx])
            {
                check[ry][rx][by][bx]=true;
                S pushing;
                P rt, bt;
                rt.y=ry; rt.x=rx;
                bt.y=by; bt.x=bx;
                pushing.r=rt; pushing.b=bt;
                pushing.cnt=now.cnt+1;
                q.push(pushing);
            }
            
            ry=now.r.y; rx=now.r.x;
            by=now.b.y; bx=now.b.x;
        }
    }
    printf("-1");
    return 0;
}
