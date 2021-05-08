#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i;
    string doors,keys;

    cin>>doors;     // (Capital) Letters of doors 
    cin>>keys;      // (Small) Letters of doors

    // Map to store keys we have, at a particular time
    unordered_map <int,int> key_map;

    // Initially, I have only one key - the first one
    key_map[keys[0] - 'a']++;

    // Number of keys needed
    int ans = 0;

    for(i=0;i<n;i++)
    {
        // If we have a key corresponding to this door, reduce (x) number of keys by 1
        if(key_map[doors[i] - 'A'] > 0)
            key_map[doors[i] - 'A']--;
        // If we don't have a key, we need one
        else
            ans++;
        
        // As I unlock door i, I get the key present in that room
        if(i < n-1)
            key_map[keys[i+1] - 'a']++;
    }

    cout<<ans<<endl;
}