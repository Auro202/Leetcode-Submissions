class Solution {
public:
    void solve(int indx, int sum, vector<vector<int> >& ans, vector<int>& nums, int target, vector<int>& a){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(a);
            return;
        }
        if(indx == nums.size()) return;
        a.push_back(nums[indx]);
        sum += nums[indx];
        solve(indx, sum, ans, nums, target, a);
        a.pop_back();
        sum -= nums[indx];
        solve(indx + 1, sum, ans, nums, target, a);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> a;
        vector<vector<int> > ans;
        solve(0, 0, ans, nums, target, a);
        return ans;
    }
};
