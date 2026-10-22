class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> arr(n); 
        int pos = 0; 
        int neg = 1; 
        for(int x : nums){
            if(x>0){
                arr[pos]=x; 
                pos+=2; 
            }
            else{
                arr[neg]=x;
                neg+=2; 
            }
        }
        return arr; 
    }
};