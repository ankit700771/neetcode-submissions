class Solution {
public:

    bool binarySearch(vector<vector<int>>& matrix, int row, int col, int target) {
        int start = 0;
        int end = col - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(matrix[row][mid] == target) return true;

            else if(matrix[row][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

       for(int i = 0; i < row; i++) {
            if(matrix[i][0] <= target && matrix[i][col-1] >= target) {
                bool ans = binarySearch(matrix, i, col, target);
                return ans;
            }
       } 
       return false;
    }
};
