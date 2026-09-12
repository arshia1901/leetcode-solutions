class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size(); 
        long long sn = n*(n+1)/2; 
        long long sn2 = n*(n+1)*(2*n+1)/6; 
        long long s = 0; 
        long long s2 = 0; 
        for(int i = 0; i<n; i++){
            s += nums[i]; 
            s2 += nums[i]*nums[i]; 
        }
        long long a = s-sn; 
        long long b = s2-sn2; 
        //repeating number = x 
        long long x = (a*a + b)/(2*a); 
        //missing number = y
        long long y = (b-a*a)/(2*a); 
        return {(int)x, (int)y}; 
    }
};