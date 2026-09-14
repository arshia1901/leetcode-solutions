class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 
        unordered_map<string, vector<string>> mpp; 
        for(string str : strs){
            string s = str; 
            sort(str.begin(), str.end()); 
            mpp[str].push_back(s); 
        }
        vector<vector<string>> result; 
        for(auto &it : mpp){
            result.push_back(it.second); 
        }
        return result; 
    }
};