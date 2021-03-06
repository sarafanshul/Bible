// Hierholzer's Algorithm for Eulerian Path/Circut O(m)
//  ===== FOR DIRECTED GRAPH =====
// https://www.youtube.com/watch?v=8MpoO2zA2l4&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=27
vector<vector<int>> adj(MAXN ,vector<int>(0));
bool visited[MAXN] = {0};
vector<int> indeg(MAXN ,0) ,outdeg(MAXN ,0) ,path;
int n ,m ,start_node = -1 ,end_node;
bool has_path = false;

bool check(){
	// for checking indeg/outdeg conditions
	int start_nodes =0 , end_nodes = 0;
	for(int i= 0 ;i <= n ;i++){
		
		if((outdeg[i] - indeg[i] > 1) || (indeg[i] - outdeg[i] > 1))
			return false;	
		else if (outdeg[i] - indeg[i] == 1){
			start_nodes++;
			start_node = i;}
		else if (indeg[i] - outdeg[i] == 1){
			end_nodes++;
			end_node = i;}
		if(outdeg[i] > 0 && start_node == -1){ start_node = i;} // if all deg are equal 
	}
	return ((end_nodes == 0 && start_nodes == 0) || 
			(end_nodes == 1 && start_nodes == 1));
}

bool check_path(){
	// for checking connected components;
	if((int)path.size() == m + 1 ) return 1;
	return 0;
}

void dfs(int v){
	// custom dfs to visit all edges
	while(outdeg[v] != 0){
		int u = adj[v][--outdeg[v]];
		dfs(u);
	}
	path.PB(v);

}

void heirholzers(){
    has_path = check();
	dfs(start_node);
	has_path = check_path();
	cout << has_path <<" \n";
	if(has_path){
	    reverse(ALL(path));
		for(size_t i = 0;i< path.size(); i++) cout << path[i] << " -> ";
		cout << "\n";
	}
}
