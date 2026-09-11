class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;  
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++; 
        }
        int majority = n/3;
        vector<int> ans; 
        for(auto item:mpp){
            if(item.second>majority){
                ans.push_back(item.first); 
            }
        }
        return ans; 
    }
};