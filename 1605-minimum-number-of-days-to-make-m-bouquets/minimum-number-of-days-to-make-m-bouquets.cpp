class Solution {
private: 
    int calcBouquets(vector<int>& bloomDay, int day, int k){
        int cnt = 0; 
        int bq = 0; 
        for(int x : bloomDay){
            if(x-day<=0){
                cnt++; 
            }
            else{
                bq = bq+ cnt/k; 
                cnt = 0; 
            }
        }
        bq += cnt/k; 
        return bq; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); 
        long long flowers = (long long)m*k;
        if(n<flowers){
            return -1; 
        }
        int ans; 
        int low = *min_element(bloomDay.begin(), bloomDay.end()); 
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        while(low<=high){
            int mid = low + (high-low)/2; 
            int bouquets = calcBouquets(bloomDay, mid, k); 
            if(bouquets>=m){
                ans = mid; 
                high = mid-1; 
            }
            else{
                low = mid+1;
            }
        }
        return ans; 
    }
};