class Solution {
public:



// Use bellman-ford algorithm where if shortest distance to source vertex gets updated after V-1 iterations then there is a negative cycle

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	     vector<int>dist(n,1e8);
	     
	    // dist[0] =0;
    for(int i=0;i<n;i++){
        dist[i]=0; // bellman-ford for each vertex as source vertex
        
        for(auto it : edges){
            int u= it[0];
            int v= it[1];
            int wt = it[2];
            
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]) // dist[u]!=1e8 : means that distance of u from source should not be infinity
            dist[v]=dist[u]+wt;
        }
    }
	   // one more iteration and if any changes to dist[] of any node we know negative cycle is there
	 // for(int i=0;i<n;i++){  this can also be done but not necessary
	 for(auto it : edges){
            int u= it[0];
            int v= it[1];
            int wt = it[2];
            
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            return 1;
        }
	 // }
        return 0;
	}
};

// another approach and it submits so it works
vector <int> dis(n,1e8);
dis[0] = 0;
int m = edges.size();
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        if(dis[edges[j][1]] > dis[edges[j][0]]+edges[j][2]){ // similar to dist[u]+wt<dist[v]
            if(i == n-1) return 1; // I dont get this shouldn't it be i==n as i==n-1 could mean relaxation  being done in n-1th iteration
            dis[edges[j][1]] = dis[edges[j][0]]+edges[j][2];
        }
    }
}
return 0;
