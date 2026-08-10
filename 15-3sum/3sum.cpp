class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i =0; i<nums.size()-1; i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }
            int target = -(nums[i]);
            int l = i+1;
            int r= nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l<r && nums[r-1]==nums[r]){
                        r--;
                    } 
                    l++; 
                    r--; 
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return result;
    }
};