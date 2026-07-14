class Solution {
public:
    set<pair<int, int>> path;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.length()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || path.count({r, c}) || board[r][c] != word[i]){
            return false;
        }
        path.insert({r, c});
        bool ans = (dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r, c - 1, i + 1));
        path.erase({r, c});
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
