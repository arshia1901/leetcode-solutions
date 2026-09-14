class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        unordered_map<int, int> mpp; 
        for(int x : nums){
            mpp[x]++; 
        }
        for(auto &it : mpp){
            pq.push({it.second, it.first}); 
            while(pq.size()>k){
                pq.pop(); 
            }
        }
        vector<int> ans; 
        while(!pq.empty()){
            int el = pq.top().second; 
            pq.pop(); 
            ans.push_back(el); 
        }
        return ans; 
    }
};