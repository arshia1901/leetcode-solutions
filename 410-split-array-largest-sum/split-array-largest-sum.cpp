class Solution {
private: 
    int calcParts(vector<int>& nums, int limit){
        int n = nums.size(); 
        int parts = 1; 
        int sum = 0; 
        for(int i = 0; i<n; i++){
            sum += nums[i]; 
            if(sum>limit){
                parts++; 
                sum = nums[i]; 
            }
        }
        return parts; 
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //k parts 
        int n = nums.size(); 
        if(k>n){
            return -1; 
        }
        int ans = -1;
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0); 
        while(low<=high){
            int mid = low + (high-low)/2; 
            int parts = calcParts(nums, mid); 
            if(parts>k){
                low = mid + 1; 
            }
            else{
                ans = mid; 
                high = mid - 1; 
            }
        }
        return ans; 
    }
};