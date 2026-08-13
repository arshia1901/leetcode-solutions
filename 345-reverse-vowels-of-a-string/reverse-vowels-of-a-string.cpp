class Solution {
public:
    string reverseVowels(string s) {
        vector<char> answer;
        vector<char> vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(char ch : s){
            if((find(vowels.begin(), vowels.end(), ch))!=vowels.end()){
                answer.push_back(ch);
            }
        }
        reverse(answer.begin(), answer.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if((find(vowels.begin(), vowels.end(), s[i]))!=vowels.end()){
                s[i]=answer[j];
                j++;
            }
        }
        return s;
    }
};