class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; 
        mpp[0]=1;
        int prefixSum = 0; 
        int count = 0; 
        for(int i = 0; i<nums.size(); i++){
            prefixSum+=nums[i]; 
            
            int needed = prefixSum-k; 
            if(mpp.find(needed)!=mpp.end()){
                count += mpp[needed];
            }
            if(mpp.find(prefixSum)!=mpp.end()){
                mpp[prefixSum]++;
            }
            else{
                mpp[prefixSum]=1;
            }
        }
        return count;
    }
};