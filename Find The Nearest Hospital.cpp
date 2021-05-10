#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, u, v, x, b;
vector< pair<int, int> > graph[100009];
vector<int> distances;
vector<bool> visited;
void djikstra(int start) {
	distances[start] = 0;
	set< pair<int, int> > s;
	s.insert(make_pair(0, start));
	while (!s.empty()) {
		pair<int, int> p = *s.begin();
		s.erase(s.begin());
		int x = p.second;
		if (visited[x]) continue;
		visited[x] = true;
		for (int i = 0; i < graph[x].size(); i++) {
			int e = graph[x][i].first, w = graph[x][i].second;
			if (distances[x] + w < distances[e]) {
				distances[e] = distances[x] + w;
				s.insert(make_pair(distances[e], e));
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		distances.assign(n + 1, 1e15);
		visited.assign(n + 1, false);
		for (int i = 0; i <= n; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < m; i++) {
			cin >> u >> v >> x;
			graph[u].push_back(make_pair(v, x));
			graph[v].push_back(make_pair(u, x));
		}

		cin >> b;
		while (b--) {
			cin >> x;
			graph[0].push_back(make_pair(x, 0));
			graph[x].push_back(make_pair(0, 0));
		}
		djikstra(0);
		for (int i = 1; i <= n; i++) {
			cout << distances[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}