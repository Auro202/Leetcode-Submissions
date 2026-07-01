class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> m;
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                m[board[i][j]]++;
                if(m[board[i][j]] > 1){
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> m;
            for(int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                m[board[j][i]]++;
                if(m[board[j][i]] > 1){
                    return false;
                }
            }
        }
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_map<char, int> m;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val == '.') continue;
                        m[val]++;
                        if (m[val] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
