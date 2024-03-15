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

int a[200001],lmin[200001],rmin[200001];

signed main()
{
    fastIO
    int n,i;
    cin >> n;
    stack<int> sl,sr;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=n;i++)
    {
        while(!sl.empty()&&a[sl.top()]>=a[i])
        {
            sl.pop();
        }
        if(!sl.empty())
            lmin[i]=sl.top();
        else
            lmin[i]=0;
        sl.push(i);
    }
    for(i=n;i>0;i--)
    {
        while(!sr.empty()&&a[sr.top()]>=a[i])
        {
            sr.pop();
        }
        if(!sr.empty())
            rmin[i]=sr.top();
        else
            rmin[i]=n+1;
        sr.push(i);
    }
    int ma=0;
    for(i=1;i<=n;i++)
    {
        ma=max(ma,(rmin[i]-lmin[i]-1)*a[i]);
    }
    cout << ma << "\n";
}