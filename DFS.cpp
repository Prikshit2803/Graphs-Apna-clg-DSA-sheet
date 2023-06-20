class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node,vector<int> adj[],map<int,int> &visited,vector<int> &ans){
        visited[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,ans);
            }
        }
        
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        map<int,int> visited;
        
        dfs(0,adj,visited,ans);
        
        return ans;
        
    }
};
