class Solution {
private: 
    int countSubarray(vector<int>&arr, int k){
        if(k<0){
            return 0; 
        }
        int n = arr.size(); 
        int sum =0; 
        int cnt =0; 
        int l =0; 
        for(int r=0; r<n; r++){
            sum += arr[r]; 
            while(sum > k){
                sum -= arr[l]; 
                l++; 
            }
            cnt = cnt + r-l+1; 
        }
        return cnt; 
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> arr;
        for(int x : nums){
            if(x%2==0){
                arr.push_back(0); 
            }
            else{
                arr.push_back(1); 
            }
        }
        int cnt1 = countSubarray(arr, k); 
        int cnt2 = countSubarray(arr, k-1); 
        return cnt1-cnt2; 
    }
};