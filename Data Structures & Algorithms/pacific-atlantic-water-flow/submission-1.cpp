class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean){
        ocean[r][c] = true;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[r][c] <= heights[nr][nc]){
                dfs(heights, nr, nc, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool> (heights[0].size(), false));
        for(int c = 0; c < heights[0].size(); c++){
            dfs(heights, 0, c, pacific);
            dfs(heights, heights.size() - 1, c, atlantic);
        }
        for(int r = 0; r < heights.size(); r++){
            dfs(heights, r, 0, pacific);
            dfs(heights, r, heights[0].size() - 1, atlantic);
        }
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
