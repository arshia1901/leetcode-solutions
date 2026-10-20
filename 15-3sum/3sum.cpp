class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result; 
        int i = 0; 
        for(int i = 0; i<n; i++){
            if(i!=0 && nums[i-1]==nums[i]){
                continue; 
            }
            else{
                int j = i+1; 
                int k = n-1; 
                while(j<k){
                int sum = nums[i]+nums[j]+nums[k]; 
                if(sum==0){
                    result.push_back({nums[i], nums[j], nums[k]}); 
                    j++; 
                    k--; 
                    while(j<k && nums[j-1]==nums[j]) j++; 
                     while(j<k && nums[k+1]==nums[k]) k--; 
                }
                else if(sum<0){
                    j++; 
                }
                else{
                    k--; 
                }
                
            }
                
            }
        }
        return result; 
    }
};