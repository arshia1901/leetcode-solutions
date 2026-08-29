class Solution {
private: 
    int f(int index, int buy, int cap, 
          vector<vector<vector<int>>>& dp, 
          vector<int>& prices) {
        
        int n = prices.size();

        // CHANGE: base case
        if(index == n ||  cap ==0) return 0;

        // ADD/CHANGE: memoization now needs cap too
        if(dp[index][buy][cap] != -1) {
            return dp[index][buy][cap]; 
        }

        if(buy) {
            return dp[index][buy][cap] = max(
                -prices[index] + f(index+1, 0, cap, dp, prices),
                f(index+1, 1, cap, dp, prices)
            ); 
        }
        else {
            return dp[index][buy][cap] = max(
                prices[index] + f(index+1, 1, cap-1, dp, prices),
                f(index+1, 0, cap, dp, prices)
            );
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 

        // CHANGE: 2D → 3D
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );

        // CHANGE: initial cap
        return f(0, 1, 2 , dp, prices);
    }
};