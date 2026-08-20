class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> distances; 
        vector<vector<int>> points; 
        //points = [[0,0], [1,1], [1,0], [0,1]]
        points.push_back(p1); 
        points.push_back(p2);
        points.push_back(p3); 
        points.push_back(p4);
        for(int i = 0; i<4; i++){
            for(int j = i+1; j<4; j++){
                int dx = points[i][0]-points[j][0]; 
                int dy = points[i][1]-points[j][1]; 
                int distance = (dx*dx)+(dy*dy); 
                distances.push_back(distance); 
            }
        }
        sort(distances.begin(), distances.end());
        if(distances[0]==0){
            return false;
        }
        if(distances[0]==distances[1] && distances[1]==distances[2] && distances[2]==distances[3] && distances[4]==distances[5]){
            if(distances[4]==2*distances[0]){
                return true;
            }
        }
        
        return false;
    }
    
};