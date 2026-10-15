class Solution {
private: 
    int f(vector<int>& nums, int start, int end) {
        int n = end-start+1;  
        vector<int> dp (n); 
        if(n==1){
            return nums[start]; 
        }
        dp[0]=nums[start]; 
        dp[1] = max(nums[start], nums[start+1]); 
        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-2]+nums[i+start], dp[i-1]); 
        }
        return dp[n-1]; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1){
            return nums[0]; 
        }
        int ans1 = f(nums, 0, n-2); 
        int ans2= f(nums, 1, n-1); 
        return max(ans1, ans2); 
    }
};