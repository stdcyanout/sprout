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

int sz[100000],weight[100000],n;
bool vis[100000];
vector<int> graph[100000];

void dfs(int node)
{
    vis[node]=1;
    for(int i:graph[node])
    {
        if(!vis[i])
        {
            dfs(i);
            sz[node]+=sz[i];
            weight[node]=max(weight[node],sz[i]);
        }
    }
    ++sz[node];
    weight[node]=max(weight[node],n-sz[node]);
}

signed main()
{
    fastIO
    int t,a,b,i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(sz,0,8*n);
        memset(weight,0,8*n);
        memset(vis,0,n);
        for(i=0;i<n;i++)
            graph[i].clear();
        for(i=0;i<n-1;i++)
        {
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(0);
        cout << min_element(weight,weight+n)-weight << "\n";
    }
}