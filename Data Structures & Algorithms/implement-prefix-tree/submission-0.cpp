struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }
    void put(Node* node, char c){
        links[c - 'a'] = node;
    }
    Node* get(char c){
        return links[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        if(node->flag == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
