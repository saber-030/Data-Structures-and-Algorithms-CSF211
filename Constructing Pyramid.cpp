// Solution: Binary Search with Hashing

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

bool is_valid(vector<ll> & v, ll k, ll height, unordered_map<ll, ll> & freq){
    ll new_size = 0;
    for(auto itr:freq) new_size += min(itr.second, k);
    return new_size/height >= k;
}

void print_solution(vector<ll> & v, ll k, ll height){
    ll n = v.size();

    vector<ll> new_v(0);
    unordered_map<ll, ll> freq;

    for(ll i = 0; i<n; i++){
        if(freq[v[i]] >= k) continue;
        freq[v[i]]++;
        new_v.push_back(v[i]);
    }

    if(new_v.size()/height < k) return;

    for(ll i = 0; i<k; i++){
        for(ll j = 0; j<height; j++){
            cout<<new_v[i+j*k]<<" ";
        }
        cout<<endl;
    }

}

void solve(){

    ll h;
    cin>>n>>h;
    vector<ll> v(n, 0);
    for(auto & i:v) cin>>i;

    unordered_map<ll, ll> freq;
    for(auto i: v) freq[i]++;

    // binary search

    ll lo = 0, hi = n/h, mid;

    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(is_valid(v, mid, h, freq)){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    cout<<lo<<endl;
    // print_solution(v, lo, h);
}

int main(int argc, char *argv[]){
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}