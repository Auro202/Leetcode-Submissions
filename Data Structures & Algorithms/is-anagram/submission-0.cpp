class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1, m2;
        for(int i = 0; i < s.length(); i++){
            m1[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            m2[t[i]]++;
        }
        for(auto it: m1){
            if(m2[it.first] != it.second){
                return false;
            }
        }
        for(auto it: m2){
            if(m1[it.first] != it.second){
                return false;
            }
        }
        return true;
    }
};
