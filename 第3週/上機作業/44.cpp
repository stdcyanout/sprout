//International Olympiad in Informatics Gold Medal
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
#define rep(i,n) for(i=0;i<(n);++i)
#define btw(a,b,c) (((a)<=(b))&&((b)<=(c)))
#define delete(q) while(!q.empty())q.pop();
using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

char graph[100][100];
bool vis[100][100];
int dy[]={1,0,-1,0},dx[]={0,1,0,-1};
int n,m;

class pii
{
    public:
        int F;
        int S;
        int D;
};

pii mp(int f,int s,int d)
{
    pii tmp;
    tmp.F=f;
    tmp.S=s;
    tmp.D=d;
    return tmp;
}

bool check(int y,int x)
{
    if(!(btw(0,y,n-1)&&btw(0,x,m-1))) 
        return false;
    if(vis[y][x])
        return false;
    if(graph[y][x]=='#')
        return false;
    return true;
}

void bfs(int y,int x)
{
    int i;
    queue<pii> q;
    q.push(mp(y,x,0));
    vis[y][x]=1;
    while(!q.empty())
    {
        int f=q.front().F,s=q.front().S,d=q.front().D;
        q.pop();
        if(graph[f][s]=='@')
        {
            cout << d << "\n";
            return;
        }
        rep(i,4)
        {
            if(check(f+dy[i],s+dx[i]))
            {
                q.push(mp(f+dy[i],s+dx[i],d+1));
                vis[f+dy[i]][s+dx[i]]=1;
            }
        }
    }
    cout << "= =\"\n";
}

signed main()
{
    fastIO
    int t,i,j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        rep(i,n) memset(vis[i],0,m);
        rep(i,n) rep(j,m) cin >> graph[i][j];
        rep(i,n)
        {
            j=find(graph[i],graph[i]+m,'K')-graph[i];
            if(j!=m)
            {
                bfs(i,j);
                break;
            }
        }
    }
}