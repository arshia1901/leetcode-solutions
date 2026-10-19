class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //2d dp 
        int n = coins.size(); 
        vector<vector<unsigned long long>> dp (n+1, vector<unsigned long long> (amount+1, 0)); 
        for(int i= 0; i<=n; i++){
            dp[i][0] = 1; 
        }
        for (int T = 1; T <= amount; T++) {
            if (T % coins[0] == 0) {
                dp[1][T] = 1;
            }
        }
        for(int i = 2; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                unsigned long long notTake = dp[i-1][j]; 
                unsigned long long take = 0; 
                if(coins[i-1]<=j){
                    take = dp[i][j-coins[i-1]]; 
                }
                dp[i][j] = take+notTake; 
            }
        }
        return (int)dp[n][amount]; 
    }
};