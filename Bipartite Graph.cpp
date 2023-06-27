//This is M-coloring algorithm and it gives TLE
class Solution {
public:

bool  issafe(int node,vector<int>adj[],int color[],int V,int k){
    for(auto it : adj[node]){
        if(color[it]==k )
        return false;
    }
    
    return true;
    // for(int i=0;i<V;i++){
    //     if(i!=node && )
    // }
}


bool solve(int node,vector<int>adj[],int color[],int V){
    
   // for(int i=0;i<V;i++){
   
   if(node==V)
   return true;
        
        for(int k=1;k<=2;k++){
            if(issafe(node,adj,color,V,k)){
                color[node]=k;
                if(solve(node+1,adj,color,V))
                return true;
                
                color[node]=0;
            }
        }
        
    //}
    
    return false;
}
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V+1]={0};
	    
	   // for(auto it : adj[3]){
	   //     cout<<it;
	   // }
	    
	    
	     if(solve(0,adj,color,V))
	     return true;
	     
	     
	     else
	     return false;
	}

};

// Find why this dont work : one problem is that for disconnected node we cant assign any color
class Solution {
public:




bool solvedfs(int node,vector<int>adj[],int color[],int V){
    
   // vis[node]=1;
    
    for(auto it : adj[node]){
        
        if( color[it]==color[node])
        return false;
        
        if(color[it]==-1){
        color[it]= !(color[node]);
        
        if(!solvedfs(it,adj,color,V))
        return false;
        
        
        }
        
    }
    
   // vis[node]=0;
    return true;
  
}
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    
	    for(int i=0;i<V;i++)
	    color[i]=-1;// this was the issue
	    
	   // vector<int> vis(V,0);
	   
	    
	    color[0]=0;
	   // color[1]=!color[0];
	   // cout<<color[1]<<" . ";
	    
	     if(solvedfs(0,adj,color,V))
	     return true;
	   
	   for(int i=1;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(solvedfs(i,adj,color,V)==false)
	            return false;
	        }
	    }
	     
	     
	  //cout<<!1<<" . ";
	   
	     //else
	     return true;
	}

};


// working dfs approach
class Solution {
public:


int ck;

bool solvedfs(int node,vector<int>adj[],int color[],int V,int k){
    
   // vis[node]=1;
   color[node]=k;
    
    for(auto it : adj[node]){
        
        if( color[it]==color[node])
        return false;
        
        if(color[it]==-1){
        //color[it]= !(color[node]);
        
        // if(k==0)
        //  ck=1;
         
        //  if(k==1)
        //  ck=0;

          ck=!k; //just this also works
        
        if(!solvedfs(it,adj,color,V,ck))
        return false;
        
        
        }
        
    }
    
   // vis[node]=0;
    return true;
  
}
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    
	    for(int i=0;i<V;i++)
	    color[i]=-1;// this was the issue
	    
	   // vector<int> vis(V,0);
	   
	    
	    //color[0]=0;
	   // color[1]=!color[0];
	   // cout<<color[1]<<" . ";
	    
	   //  if(solvedfs(0,adj,color,V))
	   //  return true;
	   
	   for(int i=1;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(solvedfs(i,adj,color,V,0)==false)
	            return false;
	        }
	    }
	     
	     
	  //cout<<!1<<" . ";
	   
	     //else
	     return true;
	}

};

//bfs approach
bool isCheck(int start,int V,vector<int>adj[],int color[])
    {
        color[start]=0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++)
	        color[i]=-1;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	           {
	               if (isCheck(i,V,adj,color)==false)
	                    return false;
	           }
	    }
	    return true;
	}


//another bfs approach
bool isBipartite(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V,-1);
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
    	        q.push(i);
    	        vis[i]=0;
    	        
    	        while(!q.empty())
    	        {
    	            int node=q.front();
    	            q.pop();
    	            for(auto it:adj[node])
    	            {
    	                if(vis[it]==-1)
    	                {
    	                    vis[it]=!vis[node];
    	                    q.push(it);
    	                }
    	                else if(vis[it]==vis[node])
    	                {
    	                    return false;
    	                }
    	            }
    	        }
	        }
	   }
	    
	    return true;
	}
