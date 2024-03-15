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

signed main()
{
    fastIO
    int t,op,n;
    queue<int> q;
    cin >> t;
    while(t--)
    {
        cin >> op;
        if(op==1)
        {
            cin >> n;
            q.push(n);
        }
        else
        {
            if(q.empty())
                cout << "empty!\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
}