//International Olympiad in Informatics Gold Medal
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

vector<int> graph[100001];
int color[100001];

bool solve(int n,int c) // color[n]=c;
{
    if(color[n]==c) return true;
    if(color[n]==3-c) return false;
    color[n]=c;
    for(int i:graph[n])
    {
        if(!solve(i,3-c))
            return false;
    }
    return true;
}

signed main()
{
    fastIO
    int t,n,m,u,v,i;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        rep(i,n) graph[i].clear();
        memset(color,0,8*n);
        while(m--)
        {
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        rep(i,n)
        {
            if(!color[i]&&!solve(i,1))
            {
                cout << "RAINBOW.\n";
                break;
            }
            else if(i==n-1)
                cout << "NORMAL.\n";
        }
    }
}