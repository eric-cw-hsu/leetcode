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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        int odd_num = 0;
        unordered_map<int, int> mp;
        traversal(root, mp, ans, odd_num);

        return ans;
    }

    void traversal(TreeNode* node, unordered_map<int, int>& mp, int& ans, int& odd_num) {
        if (node == NULL) return;
        
        mp[node->val]++;
        
        odd_num += (mp[node->val]%2 == 1) ? 1 : -1;

        if (node->right == NULL && node->left == NULL) {
            if (odd_num <= 1) {
                ans++;
            }
        }

        traversal(node->left, mp, ans, odd_num);
        traversal(node->right, mp, ans, odd_num);

        odd_num += (mp[node->val]%2 == 1) ? -1 : 1;

        if (mp[node->val] > 1) mp[node->val]--;
        else mp.erase(node->val);

        return;
    }
};
