//video link: https://www.youtube.com/watch?v=zWS2fCJGxmU

class Solution {
public:

vector<int> findpos(int x,int n){
     vector<int> pos;
    int row=n-1-(x-1)/n;
    int col=(x-1)%n;
    if(row%2==n%2) // that is if both r and n are even (or odd) due to  Boustrophedon style
    col=n-1-col;

    pos.push_back(row);
    pos.push_back(col);

    return pos;
}

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
       // boolean vis[][]= new boolean[n][n];
       vector<vector<int>> vis(n,vector<int>(n,0));
        // we will use bfs and first time n^2 encountered will be in minimum steps by virtue of bfs
        //int d={1,2,3,4,5,6};
        queue<int> q;

        q.push(1);

        vis[n-1][0]=true;

      int steps=0;
         while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();

                if(curr==(n*n)) // this step must be here as it means that n*n was in queue dont put it in for loop of k
                    return steps; 

                for(int k=1;k<7;k++){
                    int x=curr+k;
                    

                    if(x>(n*n)) break;

                    vector<int> pos=findpos(x,n);
                    int row=pos[0];
                    int col=pos[1];

                    if(vis[row][col]==1) continue;

                    vis[row][col]=1;

                    if(board[row][col]==-1)
                    q.push(x);

                    else
                    q.push(board[row][col]);

                }

            }
            steps++;
             
         }

       
       return -1;

        
    }
};

//Another faster approach
// Intuition
// The problem is asking us to find the minimum number of moves required to reach the end of a board game represented by a 2D grid (snakes and ladders game). The key observation here is that the board can be represented by a 1D array, where each element in the array corresponds to a cell in the 2D grid. This allows us to use a breadth-first search (BFS) algorithm to traverse the board and find the shortest path to the end.

// The BFS algorithm works by starting from the first cell (0th index in the 1D array) and exploring all its neighboring cells that can be reached in one move (in this case, the next 6 cells in the 1D array). For each of these neighboring cells, we check if it has a snake or ladder and update the next cell accordingly. We also keep track of the distance (number of moves) to each cell and use this information to determine the minimum number of moves required to reach the end.

// The algorithm continues this process until the end cell (last index in the 1D array) is reached, at which point the algorithm returns the minimum number of moves required to reach the end. If the end is not reached, the algorithm returns -1 indicating that it is impossible to reach the end.

// Approach
// The approach used in this solution is Breadth First Search (BFS). It first flattens the board into a 1D array and then uses a queue to keep track of the current position and the distance from the start. The algorithm starts at the first position (0) and uses a loop to check all possible moves (1-6) from the current position. If the next position has not been visited yet, it updates the distance and pushes it into the queue. If the next position is a snake or ladder, it updates the position to the end of the snake or ladder. The algorithm continues this process until it reaches the end of the board or the queue is empty. If the end of the board is reached, it returns the distance, otherwise, it returns -1.

// Complexity
// Time complexity:
// O(n2)O(n^2)O(n 
// 2
//  ) :
// where n is the size of the board. This is because the algorithm must visit each cell in the board at most once, and the number of cells in the board is n^2.

// Space complexity:
// O(n2)O(n^2)O(n 
// 2
//  ) :
// we use an array of size n^2 to store the flattened board and another array of size n^2 to store the distance from each cell to the starting cell. Additionally, we use a queue to keep track of the cells to be visited, which also takes up O(n^2) space in the worst case scenario.

// Code
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
    vector<int> flattenedBoard(n * n);
    int index = 0;
    bool leftToRight = true;
    for (int i = n - 1; i >= 0; i--) {
        if (leftToRight) {
            for (int j = 0; j < n; j++) {
                flattenedBoard[index++] = board[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                flattenedBoard[index++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;
    }
    vector<int> dist(n * n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == n * n - 1) {
            return dist[curr];
        }
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next >= n * n) {
                continue;
            }
            if (flattenedBoard[next] != -1) {
                next = flattenedBoard[next] - 1;
            }
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
    }
};
