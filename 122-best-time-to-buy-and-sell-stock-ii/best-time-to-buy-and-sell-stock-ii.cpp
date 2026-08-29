class Solution {
    private: 
    int f(int index, int buy, vector<vector<int>>& dp, vector<int>& prices){
        int n = prices.size();
        if(index==n) return 0; 
        if(dp[index][buy]!=-1){
            return dp[index][buy]; 
        }
        if(buy){
            return dp[index][buy]= max(-prices[index]+f(index+1, 0, dp, prices), f(index+1, 1, dp, prices)); 
        }
        else{
            return dp[index][buy]= max(prices[index]+f(index+1, 1, dp, prices), f(index+1, 0, dp, prices));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> dp(n, vector<int> (2, -1)); 
        return f(0, 1, dp, prices);
    }
};