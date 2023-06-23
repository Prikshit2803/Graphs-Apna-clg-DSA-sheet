// Euler tour algorithm : we do dfs and take intime and outime of each node as we go 
// video link : https://www.youtube.com/watch?v=5h1JYjin_4o
#include <iostream>
#include <vector>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
//void dfs(int src, int parent, vector<int> &g[])
vector<int> In;
vector<int> Out;
int timer=1;
void resize(int n){
	In.resize(n+1);
	Out.resize(n+1);

}

void dfs(int src,int parent,vector<int> g[]){
	In[src]=timer++;
	for(auto it : g[src]){
		if(it!=parent){
			dfs(it,src,g);
		}
	}
	Out[src]=timer++;
}



bool check(int x,int y){
	if((In[x]>In[y]) && (Out[x]<Out[y]))
	return true;

	else
	return false;
}
int32_t main() {
	int num;
	cin >> num;    //Reading input from STDIN
	// cout << "Input number is " << num << endl;	// Writing output to //STDOUT


	resize(num);
	vector<int> g[num+1];

	for(int i=0;i<num-1;i++){
		int x,y;
	cin>>x>>y;

	g[x].push_back(y);
	g[y].push_back(x);
	}

	dfs(1,0,g);

	 int q;
    cin>>q;

	for(int i=0;i<q;i++){
		int type,x,y;

		cin>>type>>x>>y;

		if(!check(x,y) && !check(y,x)){
			cout<<"NO\n";
			continue;
		}

		if(type==0){
			if(check(y,x)){
				cout<<"YES\n";
			
			}

			else{
				cout<<"NO\n";
			
			}
			
		}

		else if(type==1){
			if(check(x,y)){
				cout<<"YES\n";
			
			}

			else{
				cout<<"NO\n";
			
			}
		}
		
	}


return 0;
}

// same solbn but by youtuber
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 
vector<int> inTime;
vector<int> outTime;
int timer = 1;
 
void resize(int n){
    inTime.resize(n+1);
    outTime.resize(n+1);
}
 
void dfs(int src,int par,vector<int> g[]){
    inTime[src] = timer++;
    for(auto x:g[src]){
        if(x!=par){
            dfs(x,src,g);
        }
    }
    outTime[src] = timer++;
}
 
bool check(int x,int y){
    if(inTime[x]>inTime[y] and outTime[x]<outTime[y]) 
        return true;
    return false;
}
 
 
int32_t main() {
 
    int n;
    cin>>n;
    timer = 1;
    resize(n);
    vector<int> g[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,g);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,x,y;
        cin>>type>>x>>y;
        if(!check(x,y) and !check(y,x)){
            cout<<"NO\n";
            continue;
        }
        if(type==0){
            if(check(y,x))
                cout<<"YES\n";
            else 
                cout<<"NO\n";
        }
        else if(type==1){
            if(check(x,y))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
 
    }
 
 
 
 
    return 0;
}
