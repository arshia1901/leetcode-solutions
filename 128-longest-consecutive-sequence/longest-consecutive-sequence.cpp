class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        for(int x : nums){
            st.insert(x); 
        }
        // set is ready, traverse set 
        int longest = 0; 
        for(int x : st){
            if(st.find(x-1)==st.end()){
                // x is beginning of sequence 
                int cnt = 1; 
                while(st.find(x+1)!=st.end()){
                    //next element in sequence exists 
                    cnt++; 
                    x++; 
                }
                longest = max(longest, cnt); 
            }
            
        }
        return longest; 
    }
};