class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //variable sliding window
        //to check for duplicates use set 
        int l=0; 
        int ans=0; 
        unordered_set<char> st;
        for(int r=0; r<s.size(); r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};