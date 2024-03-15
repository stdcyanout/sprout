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

int a[1000000];

bool cmp(int x,int y)
{
    return a[x]>a[y];
}

signed main()
{
    fastIO
    int t,n,i,cnt,ans;
    cin >> t;
    while(t-- && cin >> n)
    {
        vector<int> s;
        ans=0;
        for(i=0;i<n;i++)
        {
            cnt=0;
            cin >> a[i];
            while(!s.empty() && a[s.back()]<a[i])
            {
                ++cnt;
                s.pop_back();
            }
            if(!s.empty())
            {
                auto it=lower_bound(s.begin(),s.end(),i,cmp);
                cnt+=(s.end()-it)+(it!=s.begin());
            }
            ans+=cnt;
            s.emplace_back(i);
        }
        cout << ans << "\n";
    }
}