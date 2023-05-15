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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int left, int right) {
        if (left > right) return {NULL};
        else if (left == right) return {new TreeNode(left)};

        vector<TreeNode*> ans;
        for (int k = left; k <= right; k++) {
            // left
            vector<TreeNode*> leftNodes = dfs(left, k-1);
            
            // right
            vector<TreeNode*> rightNodes = dfs(k+1, right);
            
            for (auto leftNode: leftNodes) {
                for (auto rightNode: rightNodes) {        
                    TreeNode* root = new TreeNode(k);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);    
                }
            }            
        }
        return ans;
    }
};
