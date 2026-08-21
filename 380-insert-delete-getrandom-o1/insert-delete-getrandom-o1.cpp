class RandomizedSet {
     vector<int> nums;
        unordered_map<int, int> mpp; 
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){
            //not found in set
            mpp[val]=nums.size(); 
            nums.push_back(val); 
            return true; 
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mpp.find(val)!=mpp.end()){
            int index = mpp[val]; 
            int last = nums.size()-1; 
            int lastValue = nums[last];
            swap(nums[index], nums[last]); 
            mpp[lastValue]=index;
            nums.pop_back(); 
            mpp.erase(val); 
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int getRandom() {
        int random = rand()%nums.size(); 
        return nums[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */