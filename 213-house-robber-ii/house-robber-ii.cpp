class Solution {
    private: 
    int rob1(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp(n); 
        if(n==1){
            return nums[0]; 
        }
        dp[0]= max(0, nums[0]); 
        dp[1]=max(nums[0], nums[1]); 
        for(int i = 2; i<n; i++){
            dp[i]= max(dp[i-1], dp[i-2]+nums[i]); 
        }
        return dp[n-1]; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1){
            return nums[0]; 
        }
        vector<int> temp1, temp2; 
        for(int i = 0; i<n; i++){
            if(i!=0){
                temp1.push_back(nums[i]); 
            }
            if(i!=n-1){
                temp2.push_back(nums[i]); 
            }
        }
        int ans1 = rob1(temp1); 
        int ans2= rob1(temp2);
        return max(ans1, ans2); 
    }
};