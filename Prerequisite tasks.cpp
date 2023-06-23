// My soln : Modified Topological Sort code (Kahn's Algorithm) and it is the optimal soln 
// Time Complexity: O(N + P)
// Auxiliary Space: O(N + P)
//N denoting the number of tasks, P denoting the number of prerequisite pair


class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	     vector<int> indegree(N,0),vis(N,0);
	     vector<int> ap[N];
	    queue<int> q;
	    
	    
	       
	        for(auto it: prerequisites){
	           // parent[it]=i;
	           ap[it.second].push_back(it.first);
	            indegree[it.first]++;
	        
	    }
	    
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            //ans.push_back(i);
	            //cout<<i<<":";
	            //vis[i]==1;
	            q.push(i);
	            
	            
	        }
	            
	         }
	         
	         while(!q.empty()){
	             int node=q.front();
	             vis[node]=1;
	            // cout<<node<<".";
	             q.pop();
	             
	             //ans.push_back(node);
	             
	             for(auto it : ap[node]){
	                // if(vis[it]==0){
	                     //cout<<it;
	                     
	                          indegree[it]--;
	                          
	                     
	                   
	                     
	                     if(indegree[it]==0)
	                     q.push(it);
	                     
	                    // }
	                 
	             }
	         }
	         
	         for(int i=0;i<N;i++){
	             //cout<<vis[i]<<"  ";
	              if(vis[i]==0)
	         return false;
	         }
	        
	   
	  return true;
	}
	
};

