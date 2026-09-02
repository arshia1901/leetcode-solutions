class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; 
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 
        int n = nums.size(); 
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++; 
        }
        //iterate over mpp elements 
        int count = 0; 
        for(auto it: mpp){
            if(count<k){
                pq.push({it.second, it.first}); 
                count++; 
            }
            else{
                if(it.second>pq.top().first){
                    pq.pop(); 
                    pq.push({it.second, it.first}); 
                }
            }
        }
        vector<int> result; 
        while(!pq.empty()){
            int num = pq.top().second; 
            result.push_back(num); 
            pq.pop(); 
        }
        return result; 
    }
};