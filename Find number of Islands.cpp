// Similar approach to steps by knight and rat in a maze problem
// we could have used bfs using queue also here
class Solution {
  public:
    // Function to find the number of islands.
    
    bool isvalid(int x,int y,int rows,int cols ){
        if(x<0 || x>=rows || y<0 || y>=cols)
        return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>> grid,vector<vector<int>> &vis,int x[],int y[],int i,int j,int rows ,int cols){
        vis[i][j]=1;
     // cout<<vis[i][j]<< ". " << i <<  j << ". ";
        for(int k=0;k<8;k++){
            int nx=i+x[k];
            int ny=j+y[k];
        
      
            
            if(isvalid(nx,ny,rows,cols) && grid[nx][ny]=='1' && vis[nx][ny]==0)
            dfs(grid,vis,x,y,nx,ny,rows,cols);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int rows = grid.size();
       int cols = grid[0].size();
       vector<vector<int>> vis(rows,vector<int>(cols,0));
       int x[]={1,-1,1,-1,0,0,1,-1};
       int y[]={1,-1,-1,1,1,-1,0,0};
       int ans=0;
       
       for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               //cout<<vis[i][j]<<" ";
               if(grid[i][j]=='1' && vis[i][j]==0){
                  //cout<<vis[i][j]<< ". " << i <<  j << ". ";
                   ans=ans+1;
                  dfs(grid,vis,x,y,i,j,rows,cols);
               }
              
           }
       }
  return ans;
    }
};

//similar Recursion based dfs approach
 void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited,int m,int n){
        if(i<0||i>=m||j<0||j>=n||visited[i][j]==1||grid[i][j]=='0') return;
        visited[i][j]=1;
        dfs(i+1,j,grid,visited,m,n);
        dfs(i,j+1,grid,visited,m,n);
        dfs(i,j-1,grid,visited,m,n);
        dfs(i-1,j,grid,visited,m,n);
        dfs(i+1,j+1,grid,visited,m,n);
        dfs(i-1,j-1,grid,visited,m,n);
        dfs(i+1,j-1,grid,visited,m,n);
        dfs(i-1,j+1,grid,visited,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code her
        int c=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!='0'&&visited[i][j]==0){
                    c++;
                    dfs(i,j,grid,visited,row,col);
                }
            }
        }
        return c;
    }
