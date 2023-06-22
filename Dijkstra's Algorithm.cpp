// Make a priority queue  and then explore all the neighbors of the queue top
// even using just a queue works but bit is not preferred because
//Dijkstra's algorithm can work without using a priority queue, but using a priority queue typically improves its efficiency.

// In Dijkstra's algorithm, the priority queue is used to keep track of the vertices that need to be explored next based on their distance from the source vertex. By always selecting the vertex with the minimum distance from the priority queue, the algorithm ensures that it explores the closest vertices first.

// Without a priority queue, the algorithm would need to iterate over all vertices to find the one with the minimum distance, which would result in a time complexity of O(V) for each vertex selection. With a priority queue, the minimum distance vertex can be efficiently retrieved in O(log V) time, resulting in overall better performance.

// Using a priority queue in Dijkstra's algorithm helps reduce the time complexity from O(V^2) to O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph. This makes the algorithm more efficient, especially for large graphs with many vertices and edges.

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
              vector<int> dis(V,INT_MAX);
              
    //           for(int i=0;i<n;i++)
    //           dis[i]=INT_MAX;
    
  priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>> pq;
   //This priority queue declaration should be exactly same . In this code, std::pair<int, int> represents the type of elements stored in the priority queue, std::vector<std::pair<int, int>> is the underlying container type, and std::greater<std::pair<int, int>> is the comparator function object used to compare the elements in the priority queue.
   
    
                  dis[S]=0;
                  
                //   for(auto it : adj[S]){
                //       if(dis[it[0]]>it[1])
                //       dis[it[0]]=it[1];
                //   }
                  
                 pq.push({dis[S],S});
                 //pq.push(std::make_pair(dis[S], S));
                  
                //   for(int i=0;i<V;i++){
                //       if(i!=S)
                //int i=4;
                
                while(!pq.empty()){
                    int i=pq.top().second;
                    pq.pop();
                      for(auto it : adj[i]){
                          if(it[1] + dis[i] < dis[it[0]]){
                               dis[it[0]]= it[1] + dis[i] ;
                               pq.push({dis[it[0]],it[0]});
                                }
                             
                      }
                 }
                  
                  return dis;
    }
};


// Simple queue approach
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        queue<pair<int , int>>q;
        q.push({S , 0});
        vector<int>distance(V , INT_MAX);
        distance[S] = 0;
        while(!q.empty())
        {
            int v = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto &it : adj[v])
                if(distance[it[0]] > dis+it[1])
                {
                    distance[it[0]] = dis+it[1];
                    q.push({it[0] , distance[it[0]]});
                }
        }
        return distance;
    }

// set-based approach
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ans;
        set<pair<int,int>> mySet;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        mySet.insert({0,S});
        while(!mySet.empty()){
            auto top = *(mySet.begin());
            mySet.erase(mySet.begin());
            
            for(auto i: adj[top.second]){
                if((top.first+i[1])<dist[i[0]]){
                    
                    auto record=mySet.find({dist[i[0]],i[0]});
                    if(record!=mySet.end()) mySet.erase(record);
                    
                    dist[i[0]]=top.first+i[1];
                    mySet.insert({dist[i[0]],i[0]});
                }
            }
        }
        return dist;
    }
