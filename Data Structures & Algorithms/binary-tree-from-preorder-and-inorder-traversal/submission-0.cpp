/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* recurTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int lenLeft = inRoot - inStart;
        root->left = recurTree(preorder, preStart + 1, preStart + lenLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = recurTree(preorder, preStart + lenLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = recurTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
        return root;

    }
};
