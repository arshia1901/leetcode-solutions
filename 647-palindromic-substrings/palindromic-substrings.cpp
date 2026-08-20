class Solution {
private: 
    int countPalindrome(string s, int left, int right){
        int count = 0; 
        if(s[left]==s[right]){
            count++; 
            while(left-1>=0 && right+1<s.size()){
                left--; 
                right++; 
                if(s[left]==s[right]){
                    count++; 
                }
                else{
            break;
            }
            }
        }
        
        return count;
    }
public:
    int countSubstrings(string s) {
        int count = 0; 
        for(int i = 0; i<s.size(); i++){
            count+= countPalindrome(s, i, i); //odd 
            count+= countPalindrome(s, i, i+1); //even 
        }
        return count;
    }
};