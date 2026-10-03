class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        int farthest = 0; 
        int cnt = 0; 
        int currentEnd = 0; 
        if(n==1){
            return 0; 
        }
        for(int i = 0; i<n; i++){
            farthest = max(farthest, nums[i]+i); 
            if(i==currentEnd){
                cnt++; 
                currentEnd = farthest; 
            }
            if(currentEnd == n-1){
                return cnt; 
            }
        }
        return cnt; 
    }
};