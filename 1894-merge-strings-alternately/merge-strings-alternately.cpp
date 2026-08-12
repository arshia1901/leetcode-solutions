class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0; 
        int j =0; 
        string result; 
        while(word1[i]!='\0' && word2[j]!='\0'){
            result.push_back(word1[i]);
            i++;
            result.push_back(word2[j]);
            j++;
        }
        while(word1[i]!='\0'){
            result.push_back(word1[i]);
            i++;
        }
        while(word2[j]!='\0'){
            result.push_back(word2[j]);
            j++;
        }
        return result;
    }
};