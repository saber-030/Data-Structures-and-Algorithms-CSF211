#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

int main()
{
    ll n,i,j;

    cin>>n;

    // A matrix, similar to int a[n][n]
    vector <vector <ll> > c(n,vector <ll> (n,0));

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>c[i][j];
    }

    // Left-Right diagonal, Right-left diagonal
    vector <ll> lr(2*n,0),rl(2*n,0);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            // Left-Right diagonals are indexed from left bottom corner (n-1,0) as 0
            lr[j-i+(n-1)] += c[i][j];
            
            // Right-Left diagonals are indexed from left top corner (0,0) as 0
            rl[j+i] += c[i][j];
        }
    }

    ll sum = 0;
    vector <ll> ans(2,0);   // To store max coins by W and V

    // Traverse one by one and check all cells
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            // Sum if starting from this cell = left-right Diagonal + right-left diagonal - cell value (since cell valueis counted twice)
            sum = lr[j-i+(n-1)] + rl[j+i] - c[i][j];
            
        /* 
        Since they shouldn't clash, we say that 2 sets exist:
        1. (i,j) such that i+j is even
        2. (i,j) such that i+j is odd

        A cell from set 1 and a cell from set 2 never intersect (i.e, never clash) 
        */
            if((i+j)%2 == 0)
                ans[0] = max(ans[0],sum);
            else
                ans[1] = max(ans[1],sum);
        }
    }

    cout<<(ans[0]+ans[1])%MOD<<endl;
}