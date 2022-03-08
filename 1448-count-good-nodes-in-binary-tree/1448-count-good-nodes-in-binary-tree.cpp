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
    
    void count_good_nodes(TreeNode* node, int curr_max_value) {
        if(node == nullptr) return;
        curr_max_value = max(curr_max_value, node->val);
        if(curr_max_value <= node->val) ans++;
        count_good_nodes(node->left, curr_max_value);
        count_good_nodes(node->right, curr_max_value);
    }
    
    int goodNodes(TreeNode* root) {
        count_good_nodes(root, root->val);
        return ans;
    }
};