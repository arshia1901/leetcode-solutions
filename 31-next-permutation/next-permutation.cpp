class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find pivot 
        int n = nums.size(); 
        
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                //nums[i] is pivot element 
                //find smallest greater number in suffix 
                for(int j = n-1; j>i; j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i], nums[j]); 
                        //reverse remaining array 
                        reverse(nums.begin()+i+1, nums.end()); 
                        return; 
                    }
                }
            }
        }
        //pivot not found 
            reverse(nums.begin(), nums.end()); 
    }
};