class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp; //3d array 
    vector<vector<int>> grid; //2d array 

    int solve(int r1, int c1, int r2){
        int c2 = r1+c1-r2;
        //invalid state
        if( r1>=n || c1>=n || r2>=n || c2>=n || c2<0){
            return -1e9;
        }
        //thorn 
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e9;
        }
        // already calculated 
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        //destination 
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        //current cherries 
        int cherries; 
        if(r1==r2 && c1==c2){
            cherries = grid[r1][c1];
        }
        else{
            cherries = grid[r1][c1]+grid[r2][c2];
        }
        int best = max({
            solve(r1, c1+1, r2), 
            solve(r1+1, c1, r2), 
            solve(r1, c1+1, r2+1), 
            solve(r1+1, c1, r2+1)
        });
        return dp[r1][c1][r2]=cherries+best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n= grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = solve(0, 0, 0);
        return max(0, ans);
    }

};