class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse graphs 
        int n = graph.size(); 
        vector<vector<int>> adj(n); 
        for(int i = 0; i<n; i++){
            int u = i; 
            for(auto it : graph[i]){
                adj[it].push_back(u); 
            }
        }
        vector<int> indegree(n); 
        queue<int> q; 
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++; 
            }
        }
        for(int i = 0; i<n; i++){
            if(indegree[i]==0){
                q.push(i); 
            }
        }
        vector<int> result; 
        while(!q.empty()){
            int node = q.front(); 
            q.pop(); 
            result.push_back(node); 
            for(auto it : adj[node]){
                indegree[it]--; 
                if(indegree[it]==0){
                    q.push(it); 
                }
            }
        }
        sort(result.begin(), result.end()); 
        return result; 
    }
};