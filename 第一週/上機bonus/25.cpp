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

list<int> q[101];

signed main()
{
    fastIO
    int n,m,i,j;
    cin >> n >> m;
    string op;
    while(m--)
    {
        cin >> op;
        if(op=="ADD")
        {
            cin >> i >> j;
            q[i].push_back(j);
        }
        else if(op=="LEAVE")
        {
            cin >> i;
            if(q[i].empty())
                cout << "queue " << i << " is empty!\n";
            else
                q[i].pop_front();
        }
        else
        {
            cin >> i >> j;
            q[j].splice(q[j].end(),q[i],q[i].begin(),q[i].end());
        }
    }
    for(i=1;i<=n;i++)
    {
        cout << "queue " << i << ": ";
        if(q[i].empty())
            cout << "empty\n";
        else
        {
            for(auto it=q[i].begin();it!=q[i].end();++it)
                cout << *it << " \n"[it==--q[i].end()];
        }
    }
}