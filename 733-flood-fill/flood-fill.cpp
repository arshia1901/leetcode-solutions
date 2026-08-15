class Solution {
private: 
    void bfs(int sr, int sc, vector<vector<int>>& vis, int origColor, vector<vector<int>>& image, int color){
        int m = image.size();
        int n = image[0].size();
        image[sr][sc]=color;
        vis[sr][sc]=1; 
        queue <pair<int, int>> q; 
        q.push({sr, sc});
        int delrow[]= {-1, 0, 1, 0}; 
        int delcol[]= {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first; 
            int col = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol= col+ delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==origColor && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
int n = image[0].size();

int origColor = image[sr][sc];
        if(origColor == color)
    return image;
        vector<vector<int>> vis(m, vector<int> (n, 0)); 
         
        
        bfs(sr, sc, vis, origColor, image, color);
        return image;
    }
};