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

deque<int> dq;
vector<queue<int>> q;
unordered_map<int,int> id;
int a[201005];

signed main()
{
    fastIO
    int t,n,m,x,i,j,k,tmp=1000,cnt;
    string op;
    cin >> t;
    for(cnt=1;cnt<=t;cnt++)
    {
        cout << "Line #" << cnt << "\n";
        dq.clear();
        q.clear();
        q.resize(1001);
        id.clear();
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            while(x--)
            {
                cin >> k;
                id[k]=i;
            }
        }

        cin >> m;
        while(m--)
        {
            cin >> op;
            if(op=="ENQUEUE")
            {
                cin >> x;
                if(id[x])
                {
                    if(find(dq.begin(),dq.end(),id[x])!=dq.end())
                    {
                        q[id[x]].push(x);
                    }
                    else
                    {
                        dq.push_back(id[x]);
                        q[id[x]].push(x);
                    }
                }
                else
                {
                    dq.push_back(++tmp);
                    a[tmp]=x;
                }
            }
            else
            {
                if(dq[0]<=1000)
                {
                    cout << q[dq[0]].front() << "\n";
                    q[dq[0]].pop();
                    if(q[dq[0]].empty())
                    {
                        dq.pop_front();
                    }
                }
                else
                {
                    cout << a[dq[0]] << "\n";
                    dq.pop_front();
                }
            }
        }
    }

}