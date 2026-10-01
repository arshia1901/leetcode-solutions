class Solution {
private: 
    bool dfs(int r, int c, int index, vector<vector<char>>& board, vector<vector<int>>& visited, string word){
        if(index == word.size()-1){
            return true; 
        }

        int m = board.size(); 
        int n = board[0].size(); 
        
        visited[r][c]=1; 
        int delrow[] = {-1, 0, 1, 0}; 
        int delcol[]= {0, 1, 0, -1}; 
        for(int i = 0; i<4; i++){
            int nrow = r + delrow[i]; 
            int ncol = c + delcol[i]; 
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==word[index+1]&& !visited[nrow][ncol]){
                if(dfs(nrow, ncol, index+1, board, visited, word)) return true;
            }
        }
        visited[r][c] = 0; 
        return false; 
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); 
        int n = board[0].size(); 
        vector<vector<int>> visited(m, vector<int> (n, 0)); 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, 0, board, visited, word)){
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
};