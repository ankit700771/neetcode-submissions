class Solution {
public:
    int row;
    int col; 
    int DFS(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= row || j >= col) {
            return 0;
        }

        if(grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = -1;
        
        int area = 1;


        area += DFS(grid, i-1, j);
        area += DFS(grid, i+1, j);
        area += DFS(grid, i, j-1);
        area += DFS(grid, i, j+1);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i< row; i++) {
            for(int j = 0; j< col; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea , DFS(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};
