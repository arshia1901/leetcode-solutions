class Solution {
public:
    bool isPalindrome(string s) {
        string str = ""; 
        for(char ch : s){
            if(isalnum(ch)){
                str+= tolower(ch); 
            }
        }
        int l = 0; 
        int n = str.size(); 
        int r = n-1; 
        while(l<=r){
            if(str[l]==str[r]){
                l++; 
                r--; 
            }
            else{
                return false; 
            }
        }
        return true; 
    }
};