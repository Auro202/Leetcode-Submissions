struct Node{
    Node* links[26];
    string word = "";
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Solution {
public:
    Node* root;
    vector<string> res;
    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->word = word;
    }
    void dfs(vector<vector<char>>& board, Node* root, int r, int c){
        char ch = board[r][c];
        if(ch == '#' || !root->containsKey(ch)){
            return;
        }
        Node* nextNode = root->get(ch);
        if(nextNode->word != ""){
            res.push_back(nextNode->word);
            nextNode->word = "";
        }
        board[r][c] = '#';
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int d = 0; d < 4; d++){
            int nr = r + dr[d], nc = c + dc[d];
            if(nc >= 0 && nc < board[0].size() && nr >= 0 && nr < board.size()){
                dfs(board, nextNode, nr, nc);
            }
        }
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = words.size();
        root = new Node();
        for(int i = 0; i < n; i++){
            insert(words[i]);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, root, i, j);
            }
        }
        return res;
    }
};
