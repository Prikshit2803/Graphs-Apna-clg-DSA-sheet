// For Input: 
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
// Your Output: 
// 0 1 .0 2 .2 1 .2 0 .1 0 .1 2 . // this was due to cout in 'auto it' loop        4
// Expected Output: 
// 4

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int> vis(V,0);
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min-heap
       
       pq.push({0,0}); // push 0 weight and 0 node : weight first so that arranged acc to weight
       
       int wtsum=0; // wt: weight
       
       while(!pq.empty()){
           int wt=pq.top().first;
           int node=pq.top().second;
           
           pq.pop();
           
           if(vis[node]==1){
               continue;
           }
           
           vis[node]=1;
           wtsum+=wt;
           
           for(auto it : adj[node]){
              // cout<< node << " "<<it[0] << " .";  // important to check For Input:  we find that each node traverses all it's edges as they are undirected hence we get 0 to 1 , 0 to 2 and for 2 we get 2 to 0 and 2 to 1 and then for 1 we get 1 to 0 and 1 to 2

               int nd = it[0];
               int wght = it[1];
               
               if(!vis[nd]){
                   pq.push({wght,nd});
               }
           }
           
       }
       
       return wtsum;
    }
};

// same approach but with set as it arranges by itself in ascending order
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set<pair<int,int>> st;
        st.insert({0,0});
        int dist = 0;
        vector<int> visited(V,0);
        visited[0] = 1;

        while(!st.empty()){
            auto s = *(st.begin());
            int node = s.second;
            int edgW = s.first;
            
            st.erase(st.begin());
            
            if(!visited[node]) dist += edgW;
            visited[node] = 1;
            for(auto x : adj[node]){
                int adjNode = x[0];
                int adjDist = x[1];
                if(!visited[adjNode]){
                    st.insert({adjDist,adjNode});
                }
            }
        }
        
        return dist;
    }
