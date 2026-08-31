class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; 

        int n1 = nums1.size(); 
        int n2=nums2.size(); 

        vector<int> nge(n2); 
        unordered_map<int, int> mpp; 
        
        for(int i = n2-1; i>=0; i--){
            mpp[nums2[i]]= i; 
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop(); 
            }
            if(st.empty()){
                nge[i]=-1; 
            }
            else{
                nge[i]=st.top(); 
            }
            st.push(nums2[i]); 
        }
        vector<int> result; 
        for(int i = 0; i<n1; i++){
            int index = mpp[nums1[i]]; 
            result.push_back(nge[index]); 
        }
        return result; 
    }
};