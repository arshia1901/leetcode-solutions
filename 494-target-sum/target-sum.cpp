class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total=0; 
        for(int x:nums){
            total+=x;
        }
        if(abs(target)>total){
            return 0;
        }
        if((target+total)%2!=0){
            return 0;
        }
        int subsetSum= (total+target)/2;

        vector<vector<int>> dp(n+1, vector<int>(subsetSum+1, 0));

        dp[0][0]=1;
        
        for(int i=1; i<=n; i++){
            for(int sum=0; sum<=subsetSum; sum++){
                if(nums[i-1]<=sum){
                    dp[i][sum]= dp[i-1][sum]+dp[i-1][sum-nums[i-1]];
                }
                else{
                    dp[i][sum]=dp[i-1][sum];
                }
            }
        }
        return dp[n][subsetSum];
    }
};