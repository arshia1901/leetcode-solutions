class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size(); 
        int n = s.size(); 
        int start=-1; 
        int minLen = INT_MAX; 
        int cnt = 0; 
        unordered_map<char, int> mpp; 
        //pre-insert 
        for(int i = 0; i<m; i++){
            mpp[t[i]]++; 
        }
        int l = 0; 
        //traverse s 
        for(int r=0; r<n; r++){
            if(mpp[s[r]]>0){
                cnt++; 
            }
            mpp[s[r]]--; 
            while(cnt == m){
                if(r-l+1<minLen){
                    minLen = r-l+1; 
                    start = l;
                }
                mpp[s[l]]++; 
                if(mpp[s[l]]>0){
                    cnt--; 
                }
                l++; 
            } 
        }
        return start==-1 ? "" : s.substr(start, minLen); 
    }
};