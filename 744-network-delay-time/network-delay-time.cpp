class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); 
        for(auto time : times){
            int u = time[0]; 
            int v = time[1]; 
            int tm = time[2]; 
            adj[u].push_back({v, tm}); 
        }
        vector<int> time(n+1); 
        for(int i = 0; i<=n; i++){
            time[i] = 1e9; 
        }
        time[k]=0; 
        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
        >pq; 
        pq.push({0, k}); 
        while(!pq.empty()){
            int tm = pq.top().first; 
            int node = pq.top().second; 
            pq.pop(); 
            for(auto it : adj[node]){
                int adjNode = it.first; 
                int signalTime = it.second; 
                if(signalTime + tm < time[adjNode]){
                    time[adjNode]=signalTime+tm; 
                    pq.push({time[adjNode], adjNode}); 
                }
            }
        }
        int ans; 
        for(int i = 1; i<=n; i++){
            if(time[i]==1e9){
                return -1; 
            }
            else{
                ans = max(ans, time[i]); 
            }
        }
        return ans; 
    }
};