class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int minlen = INT_MAX;
        int idx = 0;
        for(int i = 0; i < t.length(); i++){
            m[t[i]]++;
        }
        int i = 0, j = 0, req = m.size();
        if(m.find(s[i]) != m.end()){
            m[s[i]]--;
            if(m[s[i]] == 0) req--;
        }
        while(j < s.length()){
            if(req != 0){
                j++;
                if(m.find(s[j]) != m.end() && j < s.length()){
                    m[s[j]]--;
                    if(m[s[j]] == 0) req--;
                }
            }else{
                if(minlen > j - i + 1){
                    minlen = j - i + 1;
                    idx = i;
                }
                if(m.find(s[i]) != m.end()){
                    if(m[s[i]] == 0) req++;
                    m[s[i]]++;
                }
                i++;
            }
        }
        return (minlen == INT_MAX) ? "" : s.substr(idx, minlen);
    }
};
