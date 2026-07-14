class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<char>>& grid, int r, int c){
        char ch = grid[r][c];
        if(ch == '#' || ch == '0') return;
        grid[r][c] = '#';
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int d = 0; d < 4; d++){
            int nr = r + dr[d], nc = c + dc[d];
            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()){
                dfs(grid, nr, nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
