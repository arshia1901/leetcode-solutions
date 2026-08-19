class Solution {
public:
    int climbStairs(int n) {
        //vector to store values from 0 to n 
        //dp[i] represents number of ways to climb i stairs 
        vector<int> dp(n+1); 
        for(int i = 0; i<=n; i++){
            if(i==0 || i == 1){
                //for 0th stair there is only 1 way- do nothing 
                //for 1st stair there is only 1 way - from 0th stairs
                dp[i]=1;
            }
            else{
                //for ith stair- we can come from i-1 stair or i-2 stair 
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};