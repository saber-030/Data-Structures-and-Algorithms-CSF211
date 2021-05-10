// O(t.n.log(n))

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll n, m, a, b, ans = 0;
        cin>>n>>m;
        unordered_map<ll, unordered_set<ll>> graph;
        while(m--){
            cin>>a>>b;
            a--; b--;
            graph[a].insert(b);
            graph[b].insert(a);
        }

        // {degree, node}
        // degree in the priority queue is always >= 1
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for(auto i:graph){
            pq.push(make_pair(i.second.size(), i.first));
        }

        while(!pq.empty()){
            bool no_change = true;
            vector<pair<ll, ll>> to_add;
            while(!pq.empty()){
                auto cur = pq.top();
                pq.pop();
                ll node = cur.second, degree = cur.first;
                if(degree > 1) break;
                if(!degree or !graph.count(node)) continue;
                for(auto nbr:graph[node]){
                    graph[nbr].erase(node);
                    ll nbr_degree = graph[nbr].size();
                    if(nbr_degree == 0) graph.erase(nbr);
                    else to_add.push_back(make_pair(nbr_degree, nbr));
                }
                graph.erase(node);
                no_change = false;
            }
            if(no_change) break;
            for(auto & i:to_add) pq.push(i);
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}