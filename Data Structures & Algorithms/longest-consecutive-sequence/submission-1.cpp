class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        for(auto it: s){
            int len = 1;
            if(s.find(it - 1) == s.end()){
                while(s.find(it + len) != s.end()) len++;
            }
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};
