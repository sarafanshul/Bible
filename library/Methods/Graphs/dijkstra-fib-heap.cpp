const ll INF = 1e18;
vector<pair<ll ,ll >> adj[MAXN] ;
vector<ll> d , p ;
ll n ,m;

void dijkstra(ll s) {
	d.assign(n + 1, INF); p.assign(n + 1, -1); d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		ll v = q.top().second ,d_v = q.top().first; q.pop();
		if (d_v != d[v]) continue;
		for (auto &[to ,len] : adj[v]) {
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}

vector<ll> restore_path(ll s, ll t) {
	vector<ll> path;
	for (ll v = t; v != s; v = p[v]) path.push_back(v);
	path.push_back(s);
	reverse(path.begin(), path.end());
	return path;
}
