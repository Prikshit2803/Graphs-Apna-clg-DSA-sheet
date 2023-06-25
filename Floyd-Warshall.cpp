//Striver-based soln 
// Floyd-warshall can be used to detect -ve cycle : if cost[i][j]<0 at any point negative cycle exists
// Refer to striver video on this for more
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size(); // rows=cols as square matrix
	    
	    
	    for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][j]==-1) 
	               matrix[i][j]=1e8;
	               
	               
	                if(i==j)
	            matrix[i][j]=0; //not necessary to do here
	            }
	            
	           
	        }
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][j]==1e8) 
	               matrix[i][j]=-1;
	            }
	        }
	}
};
