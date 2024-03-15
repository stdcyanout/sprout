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

int a[100001];

signed main()
{
    fastIO
    int t,n,i,cur;
    bool ok;
    cin >> t;
    while(t--)
    {
        stack<int> s;
        ok=1;
        cur=0;
        cin >> n;
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<n;i++)
        {
            while(s.empty() || s.top()<a[i])
            {
                cur++;
                s.push(cur);
            }
            if(s.top()==a[i])
                s.pop();
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}