class Solution{
    void solve(int i,int j,vector<vector<int>> &m,int n,vector<string> &ans,string mov,vector<vector<int>> &vis,int di[],int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(mov);
            return;
        }
        string dir="DLRU";
        for(int ind=0;ind<4;ind++){
            int ni=i+di[ind];
            int nj=j+dj[ind];
            if(ni>=0 && nj>=0 && ni<n && nj<n && !vis[ni][nj] && m[ni][nj]==1){
                vis[i][j]=1;
                solve(ni,nj,m,n,ans,mov+dir[ind],vis,di,dj);
                vis[i][j]=0;
            }
        }
    }
    public:
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={1,0,0,-1};
        int dj[]={0,-1,1,0};
       if(m[0][0]==1)
       solve(0,0,m,n,ans,"",vis,di,dj);
       return ans;
       
    }
    /*void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }*/
};


//  Figured out and it works now : Figure out why my soln gives runtime error 
// visited array is important

void solve(vector<vector<int>> &m, int n,vector<string> &ans,string s,int i,int j,vector<vector<int>> &vis){
       
       if(i==n-1 && j==n-1){
           ans.push_back(s);
           return;
       }
       
       if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0 || vis[i][j]==1){
           return;
       
       
}

    vis[i][j]=1;

      if( j<n-1 ){
           //s=s+"R"; this also works
           solve(m, n,ans,s+"R",i,j+1,vis);
           //s.pop_back();
       }
         if(j>0 ){
           //s=s+"L";
           solve(m, n,ans,s+"L",i,j-1,vis);
           //s.pop_back();
       }
         if(i<n-1){
           //s=s+"D";
           solve(m, n,ans,s+"D",i+1,j,vis);
           //s.pop_back();
       }
         if(i>0 ){
           //s=s+"U";
           solve(m, n,ans,s+"U",i-1,j,vis);
           //s.pop_back();
       }
   
    
    vis[i][j]=0;
   return;
   
   
   
   }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0)); // this initialisation is crucial step
        
        //string s="";
        if(m[0][0]==0||m[n-1][n-1]==0)
        return ans;
        
        solve(m, n,ans,"",0,0,vis);
        
        return ans;
    }
   
};



//soln
class Solution{
    
    public:
    
    bool check(vector<vector<int>> &vis,vector<vector<int>> &m,int n,int x,int y)
    {
        if(x<0||x>=n||y<0||y>=n)
        return false;
        
        if(vis[x][y]==1 || m[x][y]==0)
        return false;
        
        return true;
    }
    
    void solve(vector<string> &ans,vector<vector<int>> &vis,vector<vector<int>> &m,int n,int x,int y,string path)
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        if(check(vis,m,n,x+1,y))
        solve(ans,vis,m,n,x+1,y,path+"D");
        
        if(check(vis,m,n,x-1,y))
        solve(ans,vis,m,n,x-1,y,path+"U");
        
        if(check(vis,m,n,x,y+1))
        solve(ans,vis,m,n,x,y+1,path+"R");
        
        if(check(vis,m,n,x,y-1))
        solve(ans,vis,m,n,x,y-1,path+"L");
        
        vis[x][y] = 0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
     
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<string> ans;
        
        if(m[0][0]==0||m[n-1][n-1]==0)
        return ans;

        solve(ans,vis,m,n,0,0,"");
        return ans;
    }
};
