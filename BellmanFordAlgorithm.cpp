class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        int inf = 1e8;
        vector<int> dist(V,inf);
        dist[S] = 0;
        for(int i = 1; i <= V-1; i++){
            for(auto it : adj){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if((dist[u]!=inf or dist[v]!=inf) and dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};
