class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(); 
        int cnt=0; 
        int l =0; 
        int len = 0; 
        for(int r=0; r<n; r++){
            if(nums[r]==0){
                cnt++; 
            }
            while(cnt>k){
                if(nums[l]==0){
                    cnt--; 
                }
                l++; 
            }

            len = max(len, r-l+1); 

        }
        return len; 
    }
};