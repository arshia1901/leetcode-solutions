class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp; 
        int n = s.size(); 
        int l =0; 
        int len =0; 
        int freq=0; 
        for(int r=0; r<n; r++){
            mpp[s[r]]++; 
            for(auto letter : mpp){
                freq = max(freq, letter.second); 
            }
            while(((r-l+1)-freq)>k){
                mpp[s[l]]--; 
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]); 
                }
                l++; 
            }
            len = max(len, r-l+1); 
        }
        return len;
    }
};