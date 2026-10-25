class Solution {
private: 
    bool possible(vector<int>& piles, int h, int k){
        int hours = 0; 
        for(int x : piles){
            hours += (x+k-1)/k; 
            if(hours>h){
                return false; 
            }
        }
        return true; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = *max_element(piles.begin(), piles.end()); 
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(possible(piles, h, mid)){
                high = mid-1; 
            }
            else{
                low = mid+1; 
            }
        }
        return low; 
    }
};