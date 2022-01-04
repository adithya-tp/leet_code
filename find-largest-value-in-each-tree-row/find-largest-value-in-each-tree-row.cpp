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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> maxes;
        if(root == nullptr) return maxes;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int ans = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* popped = q.front(); q.pop();
                ans = max(ans, popped->val);
                if(popped->left) {
                    q.push(popped->left);
                }
                if(popped->right) {
                    q.push(popped->right);
                }
            }
            maxes.push_back(ans);
        }
        return maxes;
    }
};