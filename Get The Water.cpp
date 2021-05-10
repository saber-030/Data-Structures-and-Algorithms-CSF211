/*
Author: Manav Mehta

1. The problem can be solved by using a simple BFS.
2. Firstly, we create the graph from the list of edges given and also store the weight of each edge.
3. We create an array(called 'taps') where we store the minimum time required for the water to reach tap[i].
4. The array taps[i] is initialized with LLONG_MAX.
5. We create a queue for our BFS and push the beginning tap(tap number 'K') in our queue
6. For every node in our queue, we check all it's neighbours and push them if
   the time required to reach that neighbour through the current node is less than the current time
   in the array taps[neigbour].
7. We do this process repeatedly until our queue is empty.
8. Finally, we check in our taps[i] array if there is any node which couldn't be visited in the process
9. Then we output the max of all the times 

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{

    ll n,k,e;
    cin>>n>>k>>e;
    vector<vector<ll>> edges;                       // For taking input
    for(ll i = 0;i < e; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    
        ll size = edges.size();
        ll max_time = 0, des, time; 
        vector<pair<ll,ll>> graph[n+1];             // For creating a graph using the input
        vector<ll> taps(n+1,LLONG_MAX);
        
        for(ll i = 0; i < size; i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }

        queue<pair<ll,ll>> q;
        q.push({k,0});                              // First element pushed is the k'th Tap with time = 0
        
        while(!q.empty())
        {
            pair<ll,ll>p = q.front(); 
            q.pop();
            des = p.first;
            time = p.second;
            taps[des] = min(taps[des],time);
            for(auto x : graph[des])
            {
                if(x.second + time < taps[x.first])  // Condition for pushing new elements in queue
                {
                    q.push({x.first,(x.second + time)});
                }
            }     
        }
        
        for(ll i=1;i<n+1;i++)
        {
            if(taps[i]==LLONG_MAX)       // Checking if there are any nodes which couldn't be visited
            {
                cout<<-1;
                return 0;
            }
            max_time=max({max_time,taps[i]});   // Finding the maximum of all possible times for water to reach
        }

        cout<<max_time;
    
    return 0;
}