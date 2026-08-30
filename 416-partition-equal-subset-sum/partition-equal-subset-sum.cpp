class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        
        int s = 0; 
        for(int x : nums){
            s+=x; 
        }
        if(s%2!=0){
            return false; 
        }
        int target = s/2; 
        vector<vector<bool>> dp(n, vector<bool>(target+1, false)); 
        for(int i=0; i<n; i++){
            dp[i][0]=true; 
        } 
        for(int j=0; j<=target; j++){
            if(nums[0]==j){
                dp[0][j]=true; 
            }
        }
        for(int i = 1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool notTake = dp[i-1][j]; 
                bool take = false;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]]; 
                } 
                dp[i][j]=take||notTake;
            }
        }
        return dp[n-1][target]; 
    }
};