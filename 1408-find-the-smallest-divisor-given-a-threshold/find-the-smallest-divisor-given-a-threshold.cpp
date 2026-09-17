class Solution {
private: 
    int calcSum(vector<int>& nums, int divisor){
        int sum = 0; 
        for(int x : nums){
            sum += ceil((double)x/divisor); 
        }
        return sum; 
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(); 
        int low = 1; 
        int high = *max_element(nums.begin(), nums.end()); 
        int ans; 
        while(low<=high){
            int mid = low + (high-low)/2; 
            int sum = calcSum(nums, mid); 
            if(sum<= threshold){
                ans = mid; 
                high = mid - 1; 
            }
            else{
                low = mid + 1; 
            }
        }
        return ans; 
    }
};