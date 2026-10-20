class Solution {
private: 
    int f(int start, int end, vector<int>& nums){
        int n = end-start+1; 
        if(n==1){
            return nums[start]; 
        }
        vector<int> dp(n); 
        dp[0] = nums[start]; 
        dp[1]= max(nums[start], nums[start+1]); 
        for(int i = 2; i<n; i++){
            dp[i] = max(nums[i+start]+dp[i-2], dp[i-1]); 
        }
        return dp[n-1]; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1){
            return nums[0]; 
        }
        return max(f(0, n-2, nums), f(1, n-1, nums)); 
    }
};