vector<int> dis;
int prim(){
    fill(all(dis), +INF);   
    int res = 0;
    
    priority_queue <pi, vpi, greater <pi> > S;
    S.push({dis[1] = 0, 1});
    while (!S.empty()) {
        pi u = S.top();
        S.pop();
        if (dis[u.se] != u.fi) continue;
        
        res += dis[u.se];
        dis[u.se] = 0;
        for (pi v : G[u.se]) 
            if (dis[v.fi] > v.se)
                S.push({dis[v.fi] = v.se, v.fi});
    }
    return res;
}