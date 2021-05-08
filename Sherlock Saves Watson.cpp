#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    int i,n1,n2,j;

    map <char,int> s_map,t_map;
    map <char,int> :: iterator it;
    map <char,int> :: iterator it2;

    n1 = s.length();
    n2 = t.length();

    // Put all letters in their respective maps
    for(i=0;i<n1;i++)
        s_map[s[i]]++;
    
    for(i=0;i<n2;i++)
        t_map[t[i]]++;
    
    // num denotes the number of times t can occur in s
    int num = INT_MAX;

    for(it = s_map.begin(); it != s_map.end(); it++)
    {
        it2 = t_map.find(it->first);
        if(it2 != t_map.end())
            num = min(num, it->second / it2->second);

        /*
        if 'a' occurs in s 4 times, and 'a' occurs in t 2 times, we can only have t a max of 4/2 = 2 times
        Similarly, we find the min requirement for letters (min of such divisions)
        */
    }

    // In case we can't have even a single t in s, check if num == INT_MAX
    if(num != INT_MAX)
    {
        // Remove all letters in s, which belong to t, 'num' times
        for(i=0;i<num;i++)
        {
            for(j=0;j<n2;j++)
                s_map[t[j]]--;
        }
    }

    string ans = "";                    // Answer, order of letters of s
    char first_letter = t[0];

    for(it = s_map.begin(); it != s_map.end(); it++)
    {   
        // Add all letters < First Letter of t
        if(it->first < first_letter)
        {
            for(j=0;j<it->second;j++)
            {
                ans += it->first;
            }
        }
    }

    int dir = -1;                       // Denotes if all letters == First Letter of t should be added before all the t's (-1) or after (1)
    for(i=0;i<n2;i++)
    {
        if(t[i] < first_letter)         // e.g.  t = dab, so s should be abccc"dab"dd...
        {
            dir = 1;                    //Right, i.e. after all the t's
            break;
        }
        else if(t[i] > first_letter)    // e.g.  t = dxb, so s should be abcccddd"dxb"...
        {
            dir = -1;                   //Left, i.e. before all the t's   
            break;
        }
    }

    if(dir == -1)
    {
        it = s_map.find(first_letter);

        // Add first_letter of t before all the t's
        if (it != s_map.end())
        {
            for(j = 0; j<it->second ;j++)
                ans += it->first;
        }
    }

    // If t can be done in s,
    if(num != INT_MAX)
    {
        // Add t to the ans, 'num' times
        for(i=0;i<num;i++)
            ans += t;
    }

    if(dir == 1)
    {
        it = s_map.find(first_letter);
        // Add first_letter of t after all the t's
        if (it != s_map.end())
        {
            for(j = 0; j<it->second ;j++)
                ans += it->first;
        }
    }

    for(it = s_map.begin(); it != s_map.end(); it++)
    {
        // Add all letters > First Letter of t
        if(it->first > first_letter)
        {
            for(j=0;j<it->second;j++)
            {
                ans += it->first;
            }
        }
    }

    cout<<ans<<endl;
}