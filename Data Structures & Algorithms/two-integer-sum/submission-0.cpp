class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        } 
        for(int i = 0; i < nums.size(); i++){
            if(m.find(target - nums[i]) != m.end()){
                if(2 * nums[i] == target){
                    if(m[nums[i]].size() < 2) continue;
                    else{
                        ans.push_back(m[nums[i]][0]);
                        ans.push_back(m[nums[i]][1]);
                        return ans;
                    }
                }else{
                    ans.push_back(m[nums[i]][0]);
                    ans.push_back(m[target - nums[i]][0]);
                    return ans;
                }
            } 
        }
        return ans;
    }
};