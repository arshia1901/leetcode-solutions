class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int el1=INT_MIN; 
        int el2= INT_MIN; 
        int cnt1=0, cnt2=0; 
        for(int i = 0; i<n; i++){
            if(cnt1==0 && nums[i]!=el2){
                el1 = nums[i]; 
                cnt1=1; 
            }
            else if(cnt2==0 && nums[i]!= el1){
                el2 = nums[i]; 
                cnt2=1;
            }
            else if(nums[i]==el1){
                cnt1++; 
            }
            else if(nums[i]==el2){
                cnt2++; 
            }
            else{
                cnt1--; 
                cnt2--;
            }
        }
        int count1=0; 
        int count2=0;
        vector<int> result; 
        for(int x : nums){
            if(x==el1){
                count1++; 
            }
        }
        if(count1> n/3){
            result.push_back(el1); 
        }
        for(int x:nums){
            if(x==el2){
                count2++; 
            }
        }
        if(count2>n/3){
            result.push_back(el2); 
        }
        return result; 
    }
};