//TC : O(V+E)   SC: O(V)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
       // vector<int> visited(V,0); this is another way to create a memory space for visited nodes
        queue<int> q;
        map<int,int> visited;
        
        q.push(0);
        ans.push_back(0);
        visited[0]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it : adj[node]) // iterates over all neighbours of node represented by it
        {   if(!visited[it]){
            
            ans.push_back(it);
            q.push(it);
            visited[it]=1;
            
        
         }
    
     }
        
        }
        
        return ans;
        
    }
};
