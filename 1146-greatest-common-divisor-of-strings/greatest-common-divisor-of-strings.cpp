class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(); 
        int n2= str2.size();
        while(n2!=0){
            int rem = n1%n2; 
            n1=n2; 
            n2=rem;
        }
        string result = str1.substr(0, n1);
        if((str1+str2) == (str2+str1)){
            return result;
        }
        else{
            return "";
        }
    }
};