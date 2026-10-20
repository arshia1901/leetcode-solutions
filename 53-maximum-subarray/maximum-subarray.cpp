class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp (n); 
        if(n==1){
            return nums[0]; 
        }
        dp[0]= nums[0]; 
        for(int i = 1; i<n; i++){
            dp[i] = max(nums[i], dp[i-1]+nums[i]); 
        }
        int ans = INT_MIN; 
        for(int i = 0; i<n; i++){
            ans = max(ans, dp[i]); 
        }
        return ans; 
    }
};