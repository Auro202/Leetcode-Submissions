/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& m){
        if(node == NULL) return NULL;
        if(m.count(node)){
            return m[node];
        }
        Node* copy = new Node(node->val);
        m[node] = copy;
        for(auto it: node->neighbors){
            copy->neighbors.push_back(dfs(it, m));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> m;
        Node* ans = dfs(node, m);
        return ans;
    }
};
