class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(int i = 0; i < strs.size(); i++){
            encoded += to_string(strs[i].length());
            encoded += '#';
            encoded += strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        vector<int> loc;
        int idx = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                int len = stoi(s.substr(idx, i - idx));
                ans.push_back(s.substr(i + 1, len));
                idx = i + len + 1;
                i += len + 1;
            }
        }
        return ans;
    }
};
