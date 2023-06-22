//  Approach is that edges must be atleast n-1 and then we find the no. of disconnected components and if
// disconnected components is n we need atleast n-1 edges to connect

class Solution {
public:

   void dfs(int node,vector<int> adj[],vector<int> & vis){ // the [] was essential here also 
       vis[node]=1;
            for(auto it : adj[node]){
                if(!vis[it])
                dfs(it,adj,vis);
            }
        return;
   }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;

        int disconnectedComponents=0;

        vector<int> adj[n]; //  [n] is crucial

        // for(int i=0;i<connections.size();i++){
        //     adj[connections[i][0]].push_back(connections[i][1]);
        //    adj[connections[i][1]].push_back(connections[i][0]);
        // } this also works

        for(auto &it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // both are added to adj as undirected edges
        }

        vector<int> vis(n,0);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            disconnectedComponents++;
            dfs(i,adj,vis);
        }

    }
    return disconnectedComponents-1;
        
    }
};
// For approach and disjoint based soln lokk up striver video
// video link : https://www.youtube.com/watch?v=FYrl7iz9_ZU
