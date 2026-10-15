class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses); 
        for(auto prerequisite : prerequisites){
            int u = prerequisite[1]; 
            int v = prerequisite[0]; 
            adjList[u].push_back(v); 
        }
        vector<int> indegree(numCourses, 0); 
        for(int i = 0; i<numCourses; i++){
            for(auto it : adjList[i]){
                indegree[it]++; 
            }
        }
        queue<int> q; 
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i); 
            }
        }
        int cnt = 0; 
        while(!q.empty()){
            int node = q.front(); 
            cnt++; 
            q.pop(); 
            for(auto it : adjList[node]){
                indegree[it]--; 
                if(indegree[it]==0){
                    q.push(it); 
                }
            }
        }
        if(cnt == numCourses){
            return true; 
        }
        else{
            return false; 
        }
    }
};