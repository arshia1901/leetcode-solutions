class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //balloon --> b=1, a=1, l=2, o=2, n=1
        unordered_map<char, int> mpp; 
        for(int i = 0; i<text.size(); i++){
            mpp[text[i]]++; 
        }
        return min({mpp['b'], mpp['a'], mpp['l']/2, mpp['o']/2, mpp['n']}); 
    }
};