class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; 
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        int top = 0; 
        int left = 0; 
        int bottom = m-1; 
        int right = n-1; 
        while(top<=bottom && left<=right){
            for(int j = left; j<=right; j++){
                result.push_back(matrix[top][j]); 
            }
            top = top+1; 
            for(int i = top; i<=bottom; i++){
                result.push_back(matrix[i][right]); 
            }
            right = right - 1; 
            if(top<=bottom){
                for(int j = right; j>=left; j--){
                result.push_back(matrix[bottom][j]); 
            }
            bottom = bottom - 1; 
            }
            if(left<=right){
                for(int i = bottom; i>=top; i--){
                result.push_back(matrix[i][left]); 
            }
            left = left + 1; 
            }
        }
        return result; 
    }
};