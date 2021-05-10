#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main () 
{
    // Fast IO
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Input
    ll n, m;
    cin >> n >> m;

    priority_queue <ll> pq;       // Max Heap

    ll a[n];
    for (ll i=0 ; i<n ; i++) 
    {
    	cin >> a[i];
        pq.push(a[i]);
    }
    
    // Until all tokens are used up
    while (m--) 
    {
        // Take the price element, use a token on it
    	ll cur = pq.top();
        pq.pop();
        cur /= 2;
        // Push it back to the max heap, and repeat
        pq.push(cur);
    }
 
    ll ans = 0;

    // Add all remaining prices
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
 
    cout << ans << "\n";
 
}