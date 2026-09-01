class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int n = heights.size(); 
        int maxArea = 0; 
        int nse, pse, area; 
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int element = st.top(); 
                st.pop(); 
                nse = i; 
                pse = st.empty()?-1:st.top(); 
                area = heights[element]*(nse-pse-1); 
                maxArea = max(maxArea, area); 
            }
            st.push(i); 
        }
        while(!st.empty()){
            nse = n; 
            int element = st.top(); 
            st.pop(); 
            pse = st.empty()?-1:st.top(); 
            area = heights[element]*(nse-pse-1); 
            maxArea = max(maxArea, area); 
        }
        return maxArea;
    }
};