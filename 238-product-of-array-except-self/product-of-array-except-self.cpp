class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        int prefixProduct = 1; 
        vector<int> ans(nums.size());
        ans[0]=1;
        for(int i=1; i<nums.size(); i++){
            prefixProduct*= nums[i-1]; 
            ans[i]=prefixProduct; 
        }
        int suffixProduct = 1;
        for(int i = nums.size()-2; i>=0; i--){
            suffixProduct *= nums[i+1]; 
            ans[i]*=suffixProduct; 
        }
        return ans;
    }
};