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
    int n,x;
    set<int> s;
    string op;
    cin >> n;
    while(n--)
    {
        cin >> op >> x;
        if(op=="insert")
            s.insert(x);
        else if(op=="delete")
            s.erase(x);
        else
        {
            auto it=s.lower_bound(x);
            if(it==s.begin())
                cout << *it << "\n";
            else if(it==s.end())
                cout << *(--it) << "\n";
            else
            {
                int a,b;
                a=*(it--);
                b=*it;
                if(a-x==x-b)
                    cout << b << " " << a << "\n";
                else if(a-x<x-b)
                    cout << a << "\n";
                else
                    cout << b << "\n";
            }
        }
    }
}