class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        int len = 0; 
        int l =0; 
        unordered_set<char> st; 
        for(int r=0; r<n; r++){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]); 
                l++; 
            }
            st.insert(s[r]); 
            len = max(len, r-l+1); 
        }
        return len; 
    }
};