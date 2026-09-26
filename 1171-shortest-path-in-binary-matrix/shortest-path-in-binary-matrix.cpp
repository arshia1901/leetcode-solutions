class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return -1; 
        }
        vector<vector<int>> vis(n, vector<int> (n, 0));  
        queue<tuple<int, int, int>> q; 
        q.push({0, 0, 1}); 
        vis[0][0] = 1; 
        
        while(!q.empty()){
            auto [r, c, len] = q.front(); 
            q.pop(); 
            if(r== n-1 && c==n-1){
                return len; 
            }
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    int nrow = r + i; 
                    int ncol = c+j; 
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                        vis[nrow][ncol]=1; 
                        q.push({nrow, ncol, len+1}); 
                    }
                }
            }
        }
        return -1; 
    }
};