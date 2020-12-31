vector<ll>dist;
void bfs(ll v) {
	dist.assign( n+1 , -1 );
	dist[v] = 0;
	queue<ll> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();q.pop();
		for(ll &u :adj[v]){
			if(dist[u] == -1){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
} 

pair<ll ,ll> farthest(){
	ll _max = -1 ,node = -1;
	for(ll i = 0 ;i < n ;i++) if(dist[i] > _max) _max = dist[i] , node = i;
	return MP(node ,_max);
}

ll get_diameter(){
	bfs(0);
	bfs(farthest().F);
	return farthest().S ;
}