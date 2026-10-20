class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(); 

        if(s1.size()>s2.size()){
            return false; 
        }

        vector<int> s1_freq(26, 0); 
        vector<int> s2_freq(26, 0); 
        
        for(char ch : s1){
            s1_freq[ch-'a']++; 
        }
        int l = 0; 
        int n2 = s2.size(); 
        int r = n1-1; 
        //first window 
        for(int i = l; i<=r; i++){
            s2_freq[s2[i]-'a']++; 
        }
        while(r<= n2-1){
            if(s1_freq == s2_freq){
                return true; 
            }
            s2_freq[s2[l]-'a']--; 
            l++; 
            r++; 
            if(r<n2){
                s2_freq[s2[r]-'a']++; 
            }
            
        }
        return false; 
    }
};