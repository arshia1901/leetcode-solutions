class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> times; 
        int cars = position.size(); 
        for(int i = 0; i<cars; i++){
            int dist = target - position[i]; 
            double time = (double)dist/speed[i]; 
            times.push_back({position[i], time}); 
        }
        sort(times.begin(), times.end()); 
        stack<double> fleets; 
        for(int i = cars-1; i>=0; i--){
            if(fleets.empty()){
                fleets.push(times[i].second); 
            }
            else{
                if(times[i].second > fleets.top()){
                    fleets.push(times[i].second); 
                }
            }
        }
        return fleets.size(); 
    }
};