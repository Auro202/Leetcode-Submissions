class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), area = 0;
        if(n <= 2) return 0;
        int i = 0, j = n - 1, mi = height[0], mj = height[n - 1];
        while(i < j){
            if(mj < mi){
                j--;
                mj = max(mj, height[j]);
                area += max(0, mj - height[j]);
            }else{
                i++;
                mi = max(mi, height[i]);
                area += max(0, mi - height[i]);
            }
        }
        return area;
    }
};
