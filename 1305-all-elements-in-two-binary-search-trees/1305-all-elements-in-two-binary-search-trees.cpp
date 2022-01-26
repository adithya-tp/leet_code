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
private:
    vector<int> v1, v2;
public:
    void preOrder(TreeNode* root, vector<int>& v) {
        if(!root) return;
        preOrder(root->left, v);
        v.push_back(root->val);
        preOrder(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preOrder(root1, v1);
        preOrder(root2, v2);
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while(p1 < v1.size() && p2 < v2.size()) {
            if(v1[p1] < v2[p2]) {
                ans.push_back(v1[p1]);
                p1++;
            } else {
                ans.push_back(v2[p2]);
                p2++;
            }
        }
        while(p1 < v1.size()) {
            ans.push_back(v1[p1]);
            p1++;
        }
        while(p2 < v2.size()) {
            ans.push_back(v2[p2]);
            p2++;
        }
        return ans;
    }
};