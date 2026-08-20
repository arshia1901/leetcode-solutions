class Solution {
private: 
    pair<int, int> expand(string s, int left, int right){
        int len = 0; 
        int start;
        //pair.first is the length 
        //pair.second is the start 
        if(s[left]==s[right]){
            len = right-left+1; 
            start = left;
            while(left-1>=0 && right+1<s.size() && s[left-1]==s[right+1]){
                left--; 
                right++; 
                len = right-left+1;
                start=left;
            }
        }
        return {len, start};
    }
public:
    string longestPalindrome(string s) {
        int maxLen = 0; 
        int bestStart = 0; 
        for(int i = 0; i<s.size(); i++){
            pair<int, int> odd; 
            pair<int, int> even; 
            odd = expand(s, i, i); 
            if(odd.first>maxLen){
                maxLen = odd.first; 
                bestStart = odd.second;
            }
            even = expand(s, i, i+1);
            if(even.first>maxLen){
                maxLen = even.first; 
                bestStart = even.second;
            }
        }
        return s.substr(bestStart, maxLen);
    }
};