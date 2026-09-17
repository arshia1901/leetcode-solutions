class Solution {
private: 
    int calcDays(vector<int>& weights, int cap){
        int days = 1; 
        int sum = 0; 
        for(int x : weights){
            sum += x; 
            if(sum>cap){
                days++; 
                sum = x; 
            }
        }
        return days; 
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0); 
        int ans; 
        while(low<=high){
            int mid = low + (high-low)/2; 
            int daysTaken = calcDays(weights, mid); 
            
            if(daysTaken<=days){
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