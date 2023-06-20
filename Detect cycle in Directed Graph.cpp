// TLE soln using DFS approach
class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<int> adj[], int s, vector<int>& visited, vector<int>& pathVisited) {
        visited[s] = true;
        pathVisited[s] = true;
        for (auto x : adj[s]) {
            if (visited[x] && pathVisited[x]) {
                return true;
            }
            if (dfs(adj, x, visited, pathVisited))
                return true;
        }
        pathVisited[s] = false;

        return false;
    }
};

// slight change in for loop of dfs and soln work

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[],int node,vector<int>  & visited,vector<int>  & pathvisited) {
        
        visited[node]=1;
        pathvisited[node]=1;
        
     
        
                for(int x:adj[node])
        {
            if(!visited[x] && dfs(adj,x,visited,pathvisited))
          {
                return true;
          }
            else if(pathvisited[x]==true) // it means that x is visited and pathvisited also
            {
                return true;
                
            }
        
        }
        
        pathvisited[node]=0;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0),pathvisited(V,0);
        
        
        for(int i=0;i<V;i++){
            if(!visited[i])
            if(dfs(adj,i,visited,pathvisited))
            return true;
        }
        
        return false;
        
    
    }
  
};

//another approach

 bool dfs(int v, int vis[], vector<int> adj[]){
        vis[v] = 2; 
        
        for(auto ver : adj[v]){
            if(!vis[ver]){
                if(dfs(ver, vis, adj) == true) return true;
            }
            else if(vis[ver]==2) return true; // vis[ver] = 2 means that ver is visited and pathvisited as well
        }
        
        vis[v] = 1;
        return false;
    }  

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        for(int v = 0; v < V; v++){
            if(!vis[v]){
                if(dfs(v, vis, adj) == true) return true;
            }
        }
        return false;
    }
