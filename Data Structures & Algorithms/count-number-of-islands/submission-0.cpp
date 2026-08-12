class Solution {
public:
    int row;
    int column;
    void DFS(vector<vector<char>> &grid, int i, int j) {
        if(j < 0 || i < 0 || i >= row || j >= column) {
            return;
        }

        if(grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j+1);
        DFS(grid, i, j-1);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        column = grid[0].size();
        int count = 0;

        for(int i = 0; i<row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
