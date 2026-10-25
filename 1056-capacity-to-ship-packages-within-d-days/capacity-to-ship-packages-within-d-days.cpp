class Solution {
private: 
    bool possible(vector<int>& weights, int days, int cap){
        int d = 1; 
        int sum = 0; 
        for(int x : weights){
            sum += x; 
            if(sum > cap){
                d++; 
                sum = x; 
            }
            if(d>days){
                return false; 
            }
        }
        return true; 
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0); 
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(possible(weights, days, mid)){
                high = mid-1; 
            }
            else{
                low = mid+1; 
            }
        }
        return low; 
    }
};