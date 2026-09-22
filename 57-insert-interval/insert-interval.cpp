class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0]; 
        int newEnd = newInterval[1]; 
        vector<vector<int>> result; 
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i][1]<newStart){
                //before new interval 
                result.push_back(intervals[i]); 
            }
            else if(newEnd < intervals[i][0]){
                //after 
                // insert new interval 
                result.push_back({newStart, newEnd}); 
                //append all remaining 
                for(int j = i; j<intervals.size(); j++){
                    result.push_back(intervals[j]); 
                }
                return result; 
            }
            else{
                //overlap 
                newStart = min(newStart, intervals[i][0]); 
                newEnd = max(newEnd, intervals[i][1]); 
            }
        }
        result.push_back({newStart, newEnd}); 
        return result; 
    }
};