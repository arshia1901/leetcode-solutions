class DisjointSet{
  public: 
    //constructor
    vector<int> parent, rank, size;
    DisjointSet(int n){
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){    
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return;
        } 
        if(rank[ulp_u] < rank[ulp_v]){
            //attach u to v
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            //attach v to u
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u; 
            rank[ulp_u]++; 
        }
    }
    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return; 
        }
        if(size[ulp_u]<size[ulp_v]){
            //attach u to v 
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }  
    }  
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n); 
        int extra = 0; 
        for(auto connection : connections){
            int u = connection[0]; 
            int v = connection[1]; 
            if(ds.findUPar(u)==ds.findUPar(v)){
                extra++; 
            }
            else{
                ds.unionBySize(u,v); 
            }
        }
        int components=0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i]==i){
                components++;
            }
        }
        int ans = components-1;
        if(extra>=ans){
            return ans;
        }
        return -1;
    }
};