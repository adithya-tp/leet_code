/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> io;
public:
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        if(root->left != NULL){
            inorder(root->left);
        }
        io.push_back(root->val);
        if(root->right != NULL){
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        if(io.size() == 0)
            return true;
        for(int i = 0; i < io.size() - 1; i++){
            if(io[i] >= io[i+1])
                return false;
        }
        return true;
    }
};
