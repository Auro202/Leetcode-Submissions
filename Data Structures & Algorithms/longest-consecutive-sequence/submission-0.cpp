class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        vector<int> loc;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
            if(m.find(nums[i] - 1) == m.end()){
                loc.push_back(i);
            }
        }
        int maxlen = 0;
        for(auto it: loc){
            int num = nums[it], len = 1;
            for(int i = it + 1; i < nums.size(); i++){
                if(nums[i] == num + 1){
                    len++;
                    num++;
                }
            }
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};
