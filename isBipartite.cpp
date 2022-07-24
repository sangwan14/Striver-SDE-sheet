// BFS

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V, -1);

		for(int i=0;i<V;i++){
			if(col[i]==-1){
				queue<int> q;
				q.push(i);
				col[i] = 1;//mark color as 1
				while(!q.empty()){
					int node = q.front();
					q.pop();
					for(auto it : adj[node]){
						if(col[it]!=-1){//it is already colored
							if(col[it]==col[node]) return false;//if color same, return false
						}
						else{
							q.push(it);
							col[it] = !col[node];
						}
					}
				}
			}
		}
		
		return true;
	}

};

//DFS

class Solution2 {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& col){
        if(col[node]==-1) col[node] = 1;
		for(auto it : adj[node]){
			if(col[it]!=-1){
				if(col[it]==col[node]) return false;
			}
			else{
			    col[it] = !col[node];
			    if(!dfs(it,adj,col,node)) return false;
			}
		}
		return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V, -1);

    	for(int i=0;i<V;i++){
			if(col[i]==-1){
				if(!dfs(i,adj,col,-1)) return false;
			}
		}
		
		return true;
	}

};
