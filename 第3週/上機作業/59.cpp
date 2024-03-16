//International Olympiad in Informatics Gold Medal
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
    priority_queue<int,vector<int>,greater<int>> pq;
    int t,op,n;
    cin >> t;
    while(t--)
    {
        cin >> op;
        if(op==1)
        {
            cin >> n;
            pq.push(n);
        }
        else
        {
            if(pq.empty())
                cout << "empty!\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}