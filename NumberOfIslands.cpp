//Union Find

class DSU{
public:
    int count = 0;
	vector<int> parent;
	vector<int> rank;
    
	DSU(vector<vector<char>>& grid)
	{
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n);
        rank.resize(m*n);
		for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 if (grid[i][j] == '1') {
                        int id = i * n + j;
                        parent[id] = id;
                        rank[id] = 0;
                        count++;
                }
            }
        }
	}

	int findPar(int node)
	{
		if(node == parent[node])
			return node;

		return parent[node] = findPar(parent[node]);
	}

	void unionn(int a , int b)
	{
		a = findPar(a);
		b = findPar(b);
        
        if(a!=b){
            if(rank[a] > rank[b])
                swap(a , b);

            parent[a] = b;

            if(rank[a] == rank[b])
                rank[b]++;

            count--;
        }
	}
};

class Solution {
public:
    vector<vector<int>> distance = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        DSU uf = DSU(grid);//uf = union find
        int rows = grid.size();  
        int cols = grid[0].size();  
        for (int i = 0; i < rows; i++) {  
            for (int j = 0; j < cols; j++) {  
                if (grid[i][j] == '1') {  
                    for (auto d : distance) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1') {  
                            int id1 = i*cols+j;
                            int id2 = x*cols+y;
                            uf.unionn(id1, id2);  
                        }  
                    }  
                }  
            }  
        }  
        return uf.count;  
    }
};
