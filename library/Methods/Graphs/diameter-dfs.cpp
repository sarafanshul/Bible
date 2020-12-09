/* // Using DFS

// for Diameter
To compute the diameter of a tree, you need first to 
 choose an arbitrary vertex (let's say v), then find the vertex that is 
 furthest away from v (let's say w), and then find a vertex that is 
 furthest away from w, let's sat u. 
 The distance between w and u is the diameter of the tree.

// WORKING PROPERLY
*/
vector<int> adj[MAXN];
int n ,m;
bool visited[MAXN];

int x;
void dfsUtil(int v ,int count ,int& maxCount){
	visited[v] = 1;
	count++;
	for(int u : adj[v]){
		if(!visited[u]){
			if(count >= maxCount){
				maxCount = count;
				x = u;
			}
			dfsUtil(u ,count ,maxCount);
		}
	}
}

void dfs(int v ,int& maxCount){
	memset(visited ,0 ,sizeof(visited));
	int count = 0;
	dfsUtil(v ,count + 1 ,maxCount);
}
 
int diameter(int v){
	int maxCount= INT_MIN;
	dfs(v ,maxCount);
	dfs(x ,maxCount);
	return maxCount;
}
 	
// diameter(0)