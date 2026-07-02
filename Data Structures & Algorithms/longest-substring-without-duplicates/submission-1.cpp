class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 1;
        if(s.length() == 0) return 0;
        int maxlen = 1;
        unordered_set<char> se;
        se.insert(s[l]);
        while(r < s.length()){
            while(se.find(s[r]) == se.end() && r < s.length()){
                se.insert(s[r]);
                r++;
            }
            maxlen = max(maxlen, static_cast<int>(se.size()));
            if(r == s.length()) break;
            l++;
            se.erase(s[l - 1]);
        }
        return maxlen;
    }
};
