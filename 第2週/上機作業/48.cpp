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

int n,id=0;
vector<int> preorder(2000),inorder(2000);

void traversal(int L,int R)
{
    if(L==R)
        return;
    int cur=id++;
    auto it=find(inorder.begin(),inorder.begin()+n,preorder[cur]);
    traversal(L,it-inorder.begin());
    traversal(it-inorder.begin()+1,R);
    cout << preorder[cur] << "\n";
}

signed main()
{
    fastIO
    int i;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> preorder[i];
        inorder[i]=preorder[i];
    }
    sort(inorder.begin(),inorder.begin()+n);
    traversal(0,n);
}