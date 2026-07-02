class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int area = min(heights[i], heights[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
