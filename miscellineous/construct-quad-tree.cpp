/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    void precompute(vector<vector<int>> &sum,vector<vector<int>> &grid){
        int n = grid.size();
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                sum[i][j] = sum[i-1][j] + grid[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sum[i][j] += sum[i][j-1];
            }
        }
    }
    bool isLeaf(int row,int col,int n,vector<vector<int>> &grid){
        int sum = grid[row + n-1][col + n-1];
        if(!(row == 1 && col == 1))
            sum += (grid[row - 1][col - 1] - grid[row - 1][col + n - 1] - grid[row + n - 1][col - 1]);
        return sum == 0 || sum == n*n;
    }
    Node* solve(int row,int col,int n,vector<vector<int>> &grid,vector<vector<int>> &sum){
        if(isLeaf(row+1,col+1,n,sum))
            return new Node(grid[row][col],true);

        Node* root = new Node(grid[row][col],false);
        root->topLeft = solve(row,col,n/2,grid,sum);
        root->topRight = solve(row,col+n/2,n/2,grid,sum);
        root->bottomLeft = solve(row+n/2,col,n/2,grid,sum);
        root->bottomRight = solve(row+n/2,col+n/2,n/2,grid,sum);

        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> sum(n+1,vector<int>(n+1,0));
        precompute(sum,grid);
        return solve(0,0,n,grid,sum);
        return NULL;
    }
};
