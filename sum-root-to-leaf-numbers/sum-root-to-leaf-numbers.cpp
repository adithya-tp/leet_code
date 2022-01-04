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
    int ans = 0;
    void helper(TreeNode* root, int sum) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            ans += (sum * 10 + root->val);
            return;
        }
        sum *= 10;
        sum += root->val;
        helper(root->left, sum);
        helper(root->right, sum);
        sum -= root->val;
        sum /= 10;
        
    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};