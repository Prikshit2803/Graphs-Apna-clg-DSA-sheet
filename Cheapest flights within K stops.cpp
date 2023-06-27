//DFS soln of mine : TLE
class Solution {
public:

//int ans=0;
int cost=INT_MAX;
//int stops=0;

//priority_queue<int,vector<int>,greater<int>> pq;

void dfs(int src,int dst,int k, vector<vector<int>> flights,int n,vector<int> &vis,int currcost, int stops){
    vis[src]=1;

    // if(stops>k)
    // return;
     
     if(stops==k+1 && src!=dst) // stops>=k+1 is most important step
     return;

     if(src==dst &&  currcost<cost  )
     cost=currcost;
    // pq.push(ans);

     for(auto it : flights){
         if(src==it[0] && !vis[it[1]]){
            //  ans+=it[2];
            //  stops++;
             dfs(it[1],dst,k,flights,n,vis,currcost + it[2],stops+1);
            //  ans-=it[2];
            //  stops--;
            
                vis[it[1]]=0;
         }
     }

      //vis[src]=0;

 
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //int n=flights.size();
        vector<int> vis(n,0);

        dfs(src,dst,k,flights,n,vis,0,0);
        
       
     if(cost==INT_MAX)
     return -1;
     else
        return cost;
        
       
    }
};


// Striver-based soln that tweaks dijkstra's algorithm and prioritises once with less stops
// video link : https://www.youtube.com/watch?v=9XybHVqTHcQ
class Solution {
public:


// We dont use dijkstra's directly as minm stops wala path should be priority (refer to striver for more)
// we can use normal queue here as stops increase by one hence minimum stops will be at top of queue

//priority_queue<int,vector<int>,greater<int>> pq;


    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<pair<int,int>> adj[n];

      for(auto it : flights){
          adj[it[0]].push_back({it[1],it[2]});
      }

      queue<pair<int,pair<int,int>>> q;

      vector<int> dist(n,1e9);

      dist[src]=0;

      q.push({0,{src,0}}); // stops src and cost

      while(!q.empty()){
          auto it = q.front();
          q.pop();

          int stops=it.first;
          int node=it.second.first;
          int cost=it.second.second;

          if(stops>k) continue;

          for(auto i : adj[node]){
              int ap = i.first;
              int edw = i.second;

              if(cost + edw < dist[ap] && stops<=k) // stops can be equal to k as next can be dst as dst and src are not included in stops
              {
                   dist[ap]=cost + edw;
                   q.push({stops+1,{ap,cost+edw}});
              }
          }
      }
       
       if(dist[dst]==1e9)
       return -1;

       else
       return dist[dst];
    }
};
