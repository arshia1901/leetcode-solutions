class Solution {
    private: 
    int countSubarrays(vector<int> & nums, int k){
        if(k==-1){
            return 0; 
        }
        unordered_map<int, int> mpp; 
        int n = nums.size(); 
        int l = 0; 
        int cnt = 0; 
        for(int r=0; r<n; r++){
            mpp[nums[r]]++; 
            while(mpp.size()>k){
                mpp[nums[l]]--; 
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]); 
                }
                l++; 
            }
            cnt = cnt+ r-l+1; 
        }
        return cnt; 
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt1 = countSubarrays(nums, k); 
        int cnt2 = countSubarrays(nums, k-1); 
        return cnt1-cnt2; 
    }
};