class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid){
        int m = grid.size(); 
        int n = grid[0].size(); 
        vis[row][col]=1; 
        int delrow[]={-1, 0, 1, 0}; 
        int delcol[] = {0, 1, 0, -1}; 
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i]; 
            int ncol = col + delcol[i]; 
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, vis, grid); 
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        vector<vector<int>> vis (m, vector<int>(n, 0)); 
        int cnt = 0; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++; 
                    dfs(i, j, vis, grid); 
                }
            }
        }
        return cnt; 
    }
};