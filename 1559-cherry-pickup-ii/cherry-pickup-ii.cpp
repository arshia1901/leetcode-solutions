class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size(); 
        int C = grid[0].size(); 
        //declare 3d dp vector 
        vector<vector<vector<int>>> dp (R, vector<vector<int>> (C, vector<int> (C, INT_MIN))); 
        //initial value 
        dp[0][0][C-1] = grid[0][0] + grid[0][C-1]; 

        for(int i =1; i<R; i++){
            for(int j1= 0; j1<C; j1++){
                for(int j2=0; j2<C; j2++){
                    int maxCherries = INT_MIN; 
                    for(int dj1=-1; dj1<=1; dj1++){
                        for(int dj2=-1; dj2<=1; dj2++){
                            int prevj1 = j1+dj1; 
                            int prevj2 = j2+dj2; 
                            if(prevj1>=0 && prevj1<C && prevj2>=0 && prevj2<C){
                                maxCherries = max(maxCherries, dp[i-1][prevj1][prevj2]); 
                            }
                        }
                    }
                    int currCherries; 
                    if(j1==j2){
                        currCherries = grid[i][j1]; 
                    }
                    else{
                        currCherries = grid[i][j1]+grid[i][j2]; 
                    }
                    dp[i][j1][j2] = maxCherries+currCherries; 
                }
            }
        }
        int result = INT_MIN; 
        for(int j1=0; j1<C; j1++){
            for(int j2=0; j2<C; j2++){
                result = max(result, dp[R-1][j1][j2]); 
            }
        }
        return result;
    }
};