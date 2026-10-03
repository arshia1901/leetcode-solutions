class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> result(n); 
        result[0]=1; 
        int prefix = 1; 
        int suffix = 1; 
        for(int i = 1; i<n; i++){
            prefix *= nums[i-1]; 
            result[i] = prefix; 
        }
        for(int i = n-2; i>=0; i--){
            suffix *= nums[i+1]; 
            result[i]*=suffix; 
        }
        return result; 
    }
};