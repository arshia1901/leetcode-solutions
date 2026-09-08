class Solution {
private: 
    int countSubarray(vector<int>&nums, int goal){
        if(goal<0){
            return 0; 
        }
        int n = nums.size(); 
        int l=0; 
        int cnt = 0; 
        int sum = 0; 

        for(int r = 0; r<n; r++){
            sum += nums[r]; 
            while(sum > goal){
                sum-= nums[l]; 
                l++; 
            }
            cnt = cnt+r-l+1; 
        }
        return cnt; 
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt1 = countSubarray(nums, goal); 
        int cnt2 = countSubarray(nums, goal-1); 
        return cnt1-cnt2; 
    }
};