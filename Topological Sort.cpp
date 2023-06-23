// Approach is that if indegree of any node becomes 0 we add it to our answer ans as it means that all nodes directed to it have been added in ans

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans,indegree(V,0),vis(V,0);
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	       
	        for(auto it: adj[i]){
	           // parent[it]=i;
	           
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            //ans.push_back(i);
	            //cout<<i<<":";
	            //vis[i]==1;
	            q.push(i);
	            
	        }
	            
	         }
	         
	         while(!q.empty()){
	             int node=q.front();
	            // cout<<node<<".";
	             q.pop();
	             
	             ans.push_back(node);
	             
	             for(auto it : adj[node]){
	                // if(vis[it]==0){
	                     //cout<<it;
	                     indegree[it]--;
	                     
	                     if(indegree[it]==0)
	                     q.push(it);
	                     
	                    // }
	                 
	             }
	         }
	   
	  return ans;
	}
};
