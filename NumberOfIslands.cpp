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

//DFS
class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
