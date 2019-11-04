class Solution {
    int fs = 0;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left != NULL){
            this->fs += root->val;
            if(this->hasPathSum(root->left, sum))
                return true;
            this->fs -= root->val;
        }
        if(root->right != NULL){
            this->fs += root->val;
            if(this->hasPathSum(root->right, sum))
                return true;
            this->fs -= root->val;
        }
        if(root->left == NULL && root->right == NULL){
            this->fs += root->val;
            if(this->fs == sum)
                return true;
            this->fs -= root->val;
        }
        return false;
    }
};
