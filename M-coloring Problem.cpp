class Solution{
public:

bool issafe(int  node,bool graph[101][101], int color[],int i,int n){
    for(int k=0;k<n;k++){// this explores every adjacent node
        if(k!=node && graph[k][node]==1 && color[k]==i)
        return false;
    }
    
    return true;
}


bool solve(int  node,bool graph[101][101],int m, int n,int color[]){
    if(node==n)
    return true;
    
    for(int i=1;i<=m;i++){// this decides color and m is maximum no. of colors
        if(issafe(node,graph,color,i,n)){
        color[node]=i;
        
        if(solve(node+1,graph,m,n,color))
        return true;
        
        
        color[node]=0;
        }
    }
    return false;
}
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {

// now trying striver approach 
        int color[n]={0};
         
         if(solve(0,graph,m,n,color))
         return true;
         
         else
         return false;
    }
};


// My approach will be to use minimum graph coloring by using chromatic no. but it doesn't work
// Refer to graph-coloring problem (in this same repository) for more 
       
//      int cn=0,cr; // chromatic no.
//       vector<int> adj[n];
//   // graph is n*n   and is of type such that i and represents nodes and 0 indicates no edge and 1 indicates that edge exists
//       for(int i=0;i<n;i++){
//           for(int j=0;j<n;j++){
//               if(graph[i][j]==true){
//                   adj[i].push_back(j);
//                   //adj[j].push_back(i);
//               }
//           }
//       }
//       vector<int> res(n,-1);
//       res[0]=0;
//       vector<int> avail(n+1,0);
       
//       for(int i=1;i<n;i++){
          
         
//               for(auto it : adj[i] ){
//                   if(res[it]!=-1){
//                       avail[it]=1;
//                   }
//               }
          
//           for( cr=0;cr<n;cr++){
//               if(avail[cr]==0)
//               break;
//           }
          
//           res[i]=cr;
//           cn=max(cn,cr+1);
          
//           for(auto it : adj[i] ){
//                   if(res[it]!=-1){
//                       avail[it]=0;
//                   }
//               }
//       }
    
//     // for(auto it : adj[0])
//     // cout<<it<<" " ;
//       if(cn>=m)
//       return 1;
       
//       else
//       return 0;
