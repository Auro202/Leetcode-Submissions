class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        vector<vector<int>> v(nums.size() + 1);
        for(auto it: m){
            v[it.second].push_back(it.first);
        }
        for(int i = nums.size(); i >= 0; i--){
            if(v[i].size() > 0){
                for(auto it: v[i]){
                    ans.push_back(it);
                    k--;
                    if(k == 0){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
