class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for(int x:nums){
            st.insert(x);
        }
        for(int x:st){
            if(st.find(x-1)==st.end()){
                //not found- beginning 
                int current=x;
                int length =1;
                while(st.find(current+1)!=st.end()){
                    current++;
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};