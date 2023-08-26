class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pre = vector<vector<int>> (m+1,vector<int>(n+1,0));
        for(int i=1;i<=matrix.size();i++){
            int sum = 0;
            for(int j=1;j<=matrix[0].size();j++){
                sum += matrix[i-1][j-1];
                pre[i][j] = sum;
            }
        }

        for(int j=0;j<pre[0].size();j++){
            for(int i=1;i<pre.size();i++){
                pre[i][j] += pre[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1] - pre[row1][col2+1] - pre[row2+1][col1] + pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
