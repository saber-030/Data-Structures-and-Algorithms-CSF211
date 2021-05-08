#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Brute force: Do a linear search from 1 to find the floor of the cube root of the number O(n)

// Optimal way: Binary search to find the cube root as it is monotonic. O(logn)



int main() 
{
    long long int n;
    cin >> n ;
    
    long long  int low = 0 ;

    // cutting the search space as maximum input is 10^9

    long long  int high = 1001 ;

    long long  int mid ;
    long long  int ans ;

    while( low < high )
    {
        mid = low + (high - low )/2;
        
        if(mid * mid * mid == n)
        {
            // if mid is the answer then break from the loop

            ans = mid ;
            break ;
        }
        if(mid * mid * mid >= n )
        {
            // if it is bigger than cube root change high

            high = mid ;
        }
        if(mid * mid * mid < n)
        {
            // if it is smaller than cube root change low and update ans
            
            ans = mid ;
            low = mid + 1 ;
        }
    }

    cout << ans << endl ;

    return 0;
}


