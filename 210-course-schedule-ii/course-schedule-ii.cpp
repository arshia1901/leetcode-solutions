class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(auto prerequisite:prerequisites){
            int u = prerequisite[1]; 
            int v = prerequisite[0]; 
            adj[u].push_back(v); 
        }
        vector<int> indegree(numCourses); 
        queue<int> q; 
        for(int i = 0; i<numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++; 
            }
        }
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i); 
            }
        }
        vector<int> topo; 
        while(!q.empty()){
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node); 
            for(auto it : adj[node]){
                indegree[it]--; 
                if(indegree[it]==0){
                    q.push(it); 
                }
            }
        }
        if(topo.size()!=numCourses){
            return {};
        }
        return topo; 
    }
};