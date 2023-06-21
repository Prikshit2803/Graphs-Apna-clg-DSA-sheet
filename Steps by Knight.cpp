//TLE soln due to recursion : approach is correct
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    
   // int mincnt=INT_MAX;
   
   int mincnt = INT_MAX;
    
    void solve(int i,int j,vector<int>&TargetPos,int N,int cnt,vector<vector<int>> &vis){
        
       
        
        if(i<=0 || j<=0 || j>N || i>N || vis[i][j]==1)
        return;
        
        //cout<<i<<" "<<j<<endl;
         if(i==TargetPos[0] && j==TargetPos[1]){
            mincnt=min(cnt,mincnt);
        }
        
        vis[i][j]=1;
        
       // if(i>TargetPos[0] && j<TargetPos[1])
        solve(i-2,j+1,TargetPos,N,cnt+1,vis);
        
       // if(i<TargetPos[0] && j<TargetPos[1])
        solve(i+2,j+1,TargetPos,N,cnt+1,vis);
        
       // if(i>TargetPos[0] && j>TargetPos[1])
        solve(i-2,j-1,TargetPos,N,cnt+1,vis);
        
       // if(i<TargetPos[0] && j>TargetPos[1])
        solve(i+2,j-1,TargetPos,N,cnt+1,vis);
        
        //if(i>TargetPos[0] && j>TargetPos[1])
        solve(i-1,j-2,TargetPos,N,cnt+1,vis);
        
        //if(i<TargetPos[0] || j>TargetPos[1])
        solve(i+1,j-2,TargetPos,N,cnt+1,vis);
        
        
        vis[i][j]=0;
        return;
        
        
        
        
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int cnt=0;
	   
	   vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	   
	   if(KnightPos[0]==TargetPos[0] && KnightPos[0]==TargetPos[1])
	   return 0;
	   
	   solve(KnightPos[0],KnightPos[1], TargetPos,N,cnt,vis);
	   
	   return mincnt;
	    
	}
};

//Working Soln
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    // ******* Use of BFS indicates that the first time target position is acquired it is in minmimum steps
  
   
  bool isValid(int x, int y, int N){
        
        return (x<=N && x>=1) && (y<=N && y>=1);
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    
	    int X[]= { 2,-2,2,-2,1,-1,1,-1};
	    int Y[]={ -1,1,1,-1,2,2,-2,-2};
	    
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0)),cnt(N+1,vector<int>(N+1,INT_MAX));
	    
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    cnt[KnightPos[0]][KnightPos[1]]=0;
	    
	    queue<int> qx,qy;
	    
	    qx.push(KnightPos[0]);
	    qy.push(KnightPos[1]);
	    
	    
	    while(!qx.empty()){
	        int x=qx.front();
	        int y=qy.front();
	        
	        qx.pop();
	        qy.pop();
	        
	        for(int i=0;i<8;i++){
	            int nx=x+X[i];
	            int ny=y+Y[i];
	            
	            if(isValid(nx,ny,N) && !vis[nx][ny]){
	                vis[nx][ny]=1;
	                qx.push(nx);
	                qy.push(ny);
	                cnt[nx][ny]=cnt[x][y]+1;
	            }
	        }
	    }
	    
	    return cnt[TargetPos[0]][TargetPos[1]];
       
	}
};
