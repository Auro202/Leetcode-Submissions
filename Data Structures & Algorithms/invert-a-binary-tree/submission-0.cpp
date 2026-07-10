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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* right1 = NULL, *left1 = NULL;
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        if(root->left != NULL){ 
            right1 = invertTree(root->left);
        }
        if(root->right != NULL){
            left1 = invertTree(root->right);
        }
        root->right = right1;
        root->left = left1;
        return root;
    }
};
