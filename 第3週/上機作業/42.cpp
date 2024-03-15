#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int t,n,m;
int a[1000][1000],vis[1000][1000];

void dfs(int i,int j)
{   
    if(a[i][j]==t)
        vis[i][j]=t;
    if(i-1>=0 && vis[i-1][j]!=t && a[i-1][j]==t)
        dfs(i-1,j);
    if(i+1<n && vis[i+1][j]!=t && a[i+1][j]==t)
        dfs(i+1,j);
    if(j-1>=0 && vis[i][j-1]!=t && a[i][j-1]==t)
        dfs(i,j-1);
    if(j+1<m && vis[i][j+1]!=t && a[i][j+1]==t)
        dfs(i,j+1);
}

signed main()
{
    fastIO
    int i,j,cnt;
    char c;
    cin >> t;
    ++t;
    while(t--&&t>0)
    {
        cnt=0;
        cin >> n >> m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin >> c;
                if(c=='.')
                    a[i][j]=t;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]!=t && a[i][j]==t)
                {
                    dfs(i,j);
                    ++cnt;
                }
            }
        }

        cout << cnt << "\n";
    }
}