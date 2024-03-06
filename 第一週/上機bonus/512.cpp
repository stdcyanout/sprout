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
    int n,a;
    stack<int> s;
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a<0)
        {
            if(s.empty()||s.top()!=-a)
            {
                cout << "lose light light\n";
                return 0;
            }
            s.pop();
        }
        else
        {
            s.push(a);
        }
    }
    if(s.empty())
        cout << "weed\n";
    else
        cout << "lose light light\n";
}