//This soln doesnt work It only detects cycles where a child node has an edge to its parent node, but it fails to detect other types of cycles.

bool dfs(vector<int> adj[],int node,vector<int>  & visited,vector<int>  &   parent) {
        
        visited[node]=1;
        //pathvisited[node]=1;
        
     
        
                for(int x:adj[node])
            {    
                parent[x]=node;
        
          
             if(!visited[x]) // it means that x is visited and parent also not same
            {
                if(dfs(adj,x,visited,parent))
                return true;
                
            }
            
            else if(x!=parent[node]){
                return true;
            }
        
        }
        
      // pathvisited[node]=0;
        return false;
        
    } 

 
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
      vector<int> visited(V,0),parent(V,-1);
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
               
              if(dfs(adj,i,visited,parent))
            return true;  
            }
            
        }
        
        return false;
        
    }


// working soln
class Solution {
  public:

    bool dfs(vector<int> adj[],int s, bool visited[],int parent)
    {
        
        visited[s]=true;
        
        for(int u:adj[s])
        
        {
            if(visited[u]==false)
            {
                if(dfs(adj,u,visited,s)==true)
                {
                    return true;
                }
            }
            
            // if(!visited[u] && dfs(adj,u,visited,s))
            // {
                
            //         return true;
                    
            // }. This does not work as it will send those that are not not visited but return false to dfs also to else if loop
                
            
            else if(u!=parent)
            {
                return true;
            }
        }
        
        return false;
               
    }
    
    

    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        bool visited[V];
        
        for(int i=0;i<V;i++)
        visited[i]=false;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
          if(dfs(adj,i,visited,-1)==true)
          return true;
        }
        return false;
    }

};


//  bfs approach
bool detectCycle(int start, int V, vector<int> adj[], int vis[]) {
        vis[start] = 1;
        queue<pair<int,int>> q;
        q.push({start,-1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            // checking for neighbour
            for(auto adjacentNode : adj[node]) {
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detectCycle(i,V,adj,vis) == true) {
                    return true;
                }
            }
        }
        return false;
    }
