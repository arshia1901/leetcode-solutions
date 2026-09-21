class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el; 
        int cnt = 0; 
        int n = nums.size(); 
        for(int x : nums){
            if(cnt==0){
                el = x; 
                cnt = 1; 
            }
            else if(x==el){
                cnt++; 
            }
            else{
                cnt--; 
            }
        }
        return el; 
    }
};