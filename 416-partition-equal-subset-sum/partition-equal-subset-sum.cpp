class Solution {
private: 
    bool f(int index, int target, vector<vector<int>> & dp, vector<int> &nums){
        if(target==0){
            return true; 
        }
        if(index==0){
            return (nums[0]==target); 
        }
        if(dp[index][target]!=-1){
            return dp[index][target]; 
        }
        bool notTake = f(index-1, target, dp, nums); 
        bool take = false; 
        if(nums[index]<=target){
            take = f(index-1, target-nums[index], dp, nums); 
        }
        return dp[index][target]= take||notTake; 
    }
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
        vector<vector<int>> dp(n, vector<int>(target+1, -1)); 
        return f(n-1, target, dp, nums); 
    }
};