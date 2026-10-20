class Solution {
private: 
    int f(int x, vector<int>& points, vector<int>& dp){
        if(x<0){
            return 0; 
        }
        if(x==0){
            return points[0]; 
        }
        if(dp[x]!=-1){
            return dp[x]; 
        }
        int take = points[x]+f(x-2, points, dp); 
        int notTake = f(x-1, points, dp); 
        return dp[x]= max(take, notTake); 
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end()); 
        vector<int> points(maxVal+1, 0); 
        for(int x : nums){
            points[x]+=x;
        }
        vector<int> dp(maxVal+1, -1); 
        return f(maxVal, points, dp); 
    }
};