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

int prv[100005],nxt[100005];
vector<int> ans;

signed main()
{
    fastIO
    int n,m,t,x,tmp,first=1,i;
    cin >> n >> m;
    iota(prv,prv+n+1,-1);
    iota(nxt,nxt+n+1,1);
    while(m--)
    {
        cin >> t >> x;
        if(t==0)
        {
            if(x==first)
                first=nxt[first];
            else
            {
                prv[nxt[x]]=prv[x];
                nxt[prv[x]]=nxt[x];
            }
        }
        else if(x!=first)
        {
            if(prv[x]==first)
            {
                first=x;
                tmp=prv[x];
                nxt[tmp]=nxt[x];
                prv[x]=prv[tmp];
                prv[nxt[x]]=tmp;
                prv[tmp]=x;
                nxt[x]=tmp;
            }
            else
            {
                tmp=prv[x];
                nxt[tmp]=nxt[x];
                prv[x]=prv[tmp];
                nxt[prv[tmp]]=x;
                prv[nxt[x]]=tmp;
                prv[tmp]=x;
                nxt[x]=tmp;
            }
        }
    }

    int cur=first;
    while(cur<=n)
    {
        ans.emplace_back(cur);
        cur=nxt[cur];
    }
    for(i=0;i<ans.size();i++)
    {
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}