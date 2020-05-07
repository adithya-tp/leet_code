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
    vector<int> depths;
    vector<int> parents;
    void isCousinsTraverse(TreeNode* root, int x, int y, int depth, int parent) {
        if(root != nullptr) {
            if(root->val == x || root->val == y) {
                depths.push_back(depth);
                parents.push_back(parent);
            }
            parent = root->val;
            isCousinsTraverse(root->left, x, y, depth + 1, parent);
            isCousinsTraverse(root->right, x, y, depth + 1, parent);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        isCousinsTraverse(root, x, y, 0, 0);
        return (depths[0] == depths[1] && parents[0] != parents[1]);
    }
};
