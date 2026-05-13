class Solution {
public:

    bool findDuplicate(vector<vector<char>>& grid, int sr, int er, int sc, int ec, set<int>st) {
        for(int i = sr; i<er+1; i++) {
            for(int j = sc; j<ec+1; j++) {
                if(grid[i][j] == '.') continue;
                if(st.find(grid[i][j]) != st.end()) {
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // verify row

        for(int row = 0; row<9; row++) {
            set<int> st;
            for(int col = 0; col <9; col++) {
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()) {
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // verify column

        for(int row = 0; row<9; row++) {
            set<int> st;
            for(int col = 0; col <9; col++) {
                if(board[col][row] == '.') continue;
                if(st.find(board[col][row]) != st.end()) {
                    return false;
                }
                st.insert(board[col][row]);
            }
        }

        //verify each metric

        for(int sr = 0; sr<9; sr+=3) {
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc + 2;
                set<int> st;
                bool ans = findDuplicate(board, sr, er, sc, ec , st);
                if(ans == false) return false;
            }
        }

        return true;
    }
};
