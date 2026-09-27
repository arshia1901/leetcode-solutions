class Solution {
private: 
    void backtrack(string s, int open, int close, vector<string>& ans, int n){
        if(open>n){
            return; 
        }
        if(open + close == 2*n && open==close){
            ans.push_back(s); 
            return; 
        }
        if(open<n){
            backtrack(s+'(', open+1, close, ans, n); 
        }
        if(close<open){
            backtrack(s+')', open, close+1, ans, n); 
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        backtrack("", 0, 0, ans, n); 
        return ans; 
    }
};