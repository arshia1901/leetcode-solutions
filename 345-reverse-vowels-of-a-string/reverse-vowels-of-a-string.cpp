class Solution {
public:
    string reverseVowels(string s) {
        string vowels= "aeiouAEIOU";
        int l = 0; 
        int r = s.size()-1;
        while(l<r){
            while(l<s.size() && vowels.find(s[l])==string::npos){
                l++;
            }
            while(r>0 && vowels.find(s[r])==string::npos){
                r--;
            }
            if(l<r){
                swap(s[l], s[r]);
            l++;
            r--;
            }
            
        }
        return s;
    }
};