class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        int len = 0;
        int maxLen = 0; 
        for(int i = 0; i<nums.size(); i++){
            st.insert(nums[i]); 
        }
        for(int x : st){
            if(st.find(x-1)==st.end()){
                //x is the beginning 
                len = 1;
                while(st.find(x+1)!=st.end()){
                    len++; 
                    x=x+1;
                }
                maxLen = max(maxLen, len); 
            }
        }
        return maxLen;
    }
};