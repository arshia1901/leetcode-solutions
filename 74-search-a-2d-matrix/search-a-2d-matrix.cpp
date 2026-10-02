class Solution {
private:
    bool binarySearch(vector<int>& row, int target){
        int low = 0; 
        int high = row.size()-1; 
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(row[mid]==target){
                return true; 
            }
            else if(row[mid]<target){
                low = mid + 1; 
            }
            else{
                high = mid - 1; 
            }
        }
        return false; 
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        int low = 0; 
        int high = m-1; 
        while(low<=high){
            int mid = low + (high-low)/2; 
            // does target exist in this row 
            if(matrix[mid][0]<=target && target<=matrix[mid][n-1]){
                // call function
                return binarySearch(matrix[mid], target); 
            }
            else if(target<matrix[mid][0]){
                //target is in above rows 
                high = mid-1; 
            }
            else{
                low = mid+1; 
            }
        }
        return false; 
    }
};