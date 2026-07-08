class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        m[s[i]]++;
        int maxF = 1, maxlen = 1;
        while(j < s.length()){
            if(j - i + 1 - maxF <= k){
                maxlen = max(maxlen, j - i + 1);
                j++;
                m[s[j]]++;
                maxF = max(maxF, m[s[j]]);
                if(j == s.length() - 1){
                    if(j - i + 1 - maxF <= k) maxlen = max(maxlen, j - i + 1);
                    return maxlen;
                }
            }else{
                m[s[i]]--;
                i++;
            }
        }
        return maxlen;
    }
};
