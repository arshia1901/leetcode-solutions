class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        int prefixSum = 0; 
        int cnt = 0; 
        unordered_map<int, int> mpp; 
        mpp[0]=1; 
        for(int i = 0; i<n; i++){
            prefixSum += nums[i]; 
            int needed = prefixSum - k; 
            if(mpp.find(needed)!=mpp.end()){
                // needed exists in map
                cnt += mpp[needed]; 
            }
            mpp[prefixSum]++; 
        }
        return cnt; 
    }
};