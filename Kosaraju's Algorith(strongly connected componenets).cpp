// Three steps:
// 1. Find the order of nodes and store in stack
// 2. Reverese the edges
// 3. Do dfs
// This algo works only for directed graphs
//Video Link : https://www.youtube.com/watch?v=R6uoSjZ2imo

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfstime(int node,vector<vector<int>>& adj,vector<int> &vis,stack<int> &st){
	    vis[node]=1;
	    
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfstime(it,adj,vis,st);
	            
	        }
	    }
	    
	    st.push(node);
	    return;
	}
	
		void dfs(int node,vector<vector<int>>& adj,vector<int> &v){
	    v[node]=1;
	    
	    for(auto it : adj[node]){
	        if(!v[it]){
	            dfs(it,adj,v);
	            
	        }
	    }
	    
	    //st.push(it);
	    return;
	}
	

	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0),v(V,0);
        
        int sconnected=0;
        
        stack<int> st;
        
        vector<vector<int>> ap(V); //this works
        //vector<int> ap[V]; this can also work
        
        
        for(int i=0;i<V;i++){
            if(!vis[i])
        	dfstime(i,adj,vis,st); // arranging 
        	
        	}
        	
        	
        // now need to reverse edges
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                ap[it].push_back(i);
            }
        }
        	
        
        while(!st.empty()){
            
            int node=st.top();
            
            st.pop();
            
            if(!v[node]){
                sconnected++;
                dfs(node,ap,v);
            }
            
        }
        
        return sconnected;
        
        
    }
};
