class DisjointSet{
    
  public: 
  vector<int> parent, rank, size;
    //constructor
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); 
        DisjointSet ds(V); 
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j]==1){
                    //there is an edge bw i and j 
                    ds.unionBySize(i, j);
                }
            }
        }
        //count number of ultimate parents 
        int count = 0; 
        for(int i = 0; i<V; i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        return count;
    }
};