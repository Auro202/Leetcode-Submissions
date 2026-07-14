struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string& word, int i, Node* node){
        if(i == word.length()) return node->flag;
        if(word[i] == '.'){
            for(int c = 0; c < 26; c++){
                if(node->links[c] != NULL && dfs(word, i + 1, node->links[c])){
                    return true;
                }
            }
            return false;
        }else{
            if(!node->containsKey(word[i])){
                return false;
            }
            return dfs(word, i + 1, node->get(word[i]));
        }
    }
};
