class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size(); 
        stack<char> st; 
        for(int i = 0; i<n; i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]); 
            }
            else{
                st.pop(); 
            }
        }
        string result=""; 
        while(!st.empty()){
            char c = st.top(); 
            st.pop();
            result+=c; 
        }
        reverse(result.begin(), result.end()); 
        return result; 
    }
};