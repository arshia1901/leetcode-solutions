class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> result; 
        unordered_map<int, int> mpp; 
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++; 
        }
        int freq = n/3; 
        for(auto num : mpp){
            if(num.second>freq){
                result.push_back(num.first); 
            }
        }
        return result; 
    }
};