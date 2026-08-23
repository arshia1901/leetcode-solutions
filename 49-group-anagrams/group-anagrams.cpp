class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 
        unordered_map<string, vector<string>> mpp;
        for(int i = 0; i<n; i++){
            string key = strs[i]; 
            sort(key.begin(), key.end()); 
            mpp[key].push_back(strs[i]);   
        }
        vector<vector<string>> result;  
        for(auto entry:mpp){
        result.push_back(entry.second);
        }
        return result;
    }
};