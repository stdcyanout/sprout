#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
#define pb emplace_back

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
int num[100001];
int dfs(int n)
{
    if(num[n])
        return num[n];
    if(graph[n].empty())
        return num[n]=1;
    for(int i:graph[n])
        num[n]+=dfs(i);
    num[n]+=1;
    return num[n];
}

signed main()
{
    fastIO
    int t,n,m,x,y,q,i;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            graph[i].clear();
            num[i]=0;
        }
        while(m--)
        {
            cin >> x >> y;
            graph[x].pb(y);
        }
        cin >> q;
        while(q--)
        {
            cin >> x;
            cout << dfs(x) << "\n";
        }
    }
}