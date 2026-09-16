class Solution {
private: 
    long long calcHours(vector<int>& piles, int k){
        long long hours=0; 
        for(int x : piles){
            hours += ceil((double)x/k);  
        }
        return hours; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 
        int low = 1; 
        int ans; 
        int high = *max_element(piles.begin(), piles.end()); 
        while(low<=high){
            int mid = low + (high-low)/2; 
            long long hours = calcHours(piles, mid); 
            if(hours<=h){
                ans = mid; 
                high = mid -1 ; 
            }
            else{
                low = mid + 1; 
            }
        }
        return ans; 
    }
};