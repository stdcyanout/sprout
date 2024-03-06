#include <bits/stdc++.h>
using namespace std;
void solve(int N,int order[])
{
    int i,j,pos[N+1];
    stack<int> GT01,GT02;
    for(i=1;i<=N;i++)
    {
        push_train();
        pos[i]=1;
        GT01.push(i);
    }
    for(i=0;i<N;i++)
    {
        if(pos[order[i]]==1)
        {
            while(GT01.top()!=order[i])
            {
                move_station_1_to_2();
                pos[GT01.top()]=2;
                GT02.push(GT01.top());
                GT01.pop();
            }
            move_station_1_to_2();
            pop_train();
            pos[GT01.top()]=0;
            GT01.pop();
        }

        else if(pos[order[i]]==2)
        {
            while(GT02.top()!=order[i])
            {
                move_station_2_to_1();
                pos[GT02.top()]=1;
                GT01.push(GT02.top());
                GT02.pop();
            }
            pop_train();
            pos[GT02.top()]=0;
            GT02.pop();
        }

        else
            no_solution();
    }
}