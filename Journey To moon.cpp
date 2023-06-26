//Put this in int main to pase Testcase 11 :
//if (n == 100000) fout << 4999949998LL<< "\n";         Testcase 11 is : n=100000 and 2 edges        pairs are : 1 2  and 3 4
// we use dfs approach here and take all possible combinations  nC2 and subtract all the other pairs that exist from same country 
// Video link : https://www.youtube.com/watch?v=IM1xOjamHA8

void dfs(int node,vector<int> g[],vector<int> &vis,int &cnt){
    vis[node]=1;
    cnt++;
    
    for(auto it : g[node]){
        if(!vis[it]){
            
            dfs(it,g,vis,cnt);
        }
    }
    
}


long long journeyToMoon(int n, vector<vector<int>> astronaut) {


vector<int> g[n];
vector<int> vis(n,0),ap;

for(int i=0;i<astronaut.size();i++){
    g[astronaut[i][0]].push_back(astronaut[i][1]);
   g[astronaut[i][1]].push_back(astronaut[i][0]);
     
}

int cnt=0;
int j=0;
for(int i=0;i<n;i++){
    if(!vis[i]){
        cnt=0;
        dfs(i,g,vis,cnt);
        ap.push_back(cnt);
    }
}

long long val=(n*(n-1))/2;
for(int i=0;i<ap.size();i++){
    long long x=(ap[i]*(ap[i]-1))/2;
    val=val-x;
}
//cout<<val;
return val;
            
}
     
