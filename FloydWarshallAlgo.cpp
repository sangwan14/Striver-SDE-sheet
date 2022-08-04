class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(matrix[i][k]!=-1 and matrix[k][j]!=-1){
	                    if(matrix[i][j]==-1) matrix[i][j] = matrix[i][k]+matrix[k][j];
	                    else matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                }
	            }
	        }
	    }
	}
};

//Time Complexity - O(N^3)

/*
 Differences btw Floyd and Dijstra Algo:
 1) Dijstra is SSSP when min distance from one source node is needed while Floyd is used for all nodes
 2) TC of Dijstra is- O(E log V) but when used for all nodes it becomes O(V3 log V) while of Floyd is O(V3)
 3) Floyd can work for negative edges(no negative cycles) but Dijstra can't.
 */
