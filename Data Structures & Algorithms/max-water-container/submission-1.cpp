class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), mazArea = 0;
        int i = 0, j = n - 1;
        while(i < j){
            int area = (j - i) * min(heights[i], heights[j]);
            if(heights[i] <= heights[j]) i++;
            else j--;
            mazArea = max(mazArea, area);
        }
        return mazArea;
    }
};
