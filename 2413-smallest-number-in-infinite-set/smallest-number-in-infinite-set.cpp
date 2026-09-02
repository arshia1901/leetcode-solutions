class SmallestInfiniteSet {
public:
    int next; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    unordered_set<int> st; 
    SmallestInfiniteSet() {
        next = 1; 
    }
    
    int popSmallest() {
        //heap is not empty
        if(!pq.empty()){
            //min element from heap to be removed 
            int num = pq.top(); 
            pq.pop(); 
            st.erase(num); 
            return num; 
        }
        else{
            int num = next; 
            next = next+1;  
            return num; 
        }
    }
    
    void addBack(int num) {
        if(num>=next){
            return; 
        }
        else if(st.find(num)!=st.end()){
            return; 
        }
        else{
            pq.push(num); 
            st.insert(num); 
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */