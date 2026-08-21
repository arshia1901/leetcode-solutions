class DetectSquares {
    unordered_map<int, unordered_map<int, int>> points;
    //{x-> {y->freq}}
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0]; 
        int y = point[1]; 
        points[x][y]++; 
    }
    
    int count(vector<int> point) {
        //get x and y coordinates 
        int ans = 0;
        int x = point[0]; 
        int y = point[1]; 
        for(auto p : points){
            int x2 = p.first; 
            if(p.second.find(y)!=p.second.end() && x2!=x){
                //another point found 
                //query (x, y), other point(x2, y)
                int side = abs(x-x2);
                //upper square 
                if(p.second.find(y+side)!=p.second.end() && points[x].find(y+side)!= points[x].end()){
                    //access frequencies 
                    ans += p.second[y]*p.second[y+side]*points[x][y+side];
                }
                //lower square 
                if(p.second.find(y-side)!=p.second.end() && points[x].find(y-side)!= points[x].end()){
                    ans+= p.second[y]*p.second[y-side]*points[x][y-side];
                }
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */