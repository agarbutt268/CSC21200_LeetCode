#include <climits>
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
    bool _validate(TreeNode* node, int lower_bound, int upper_bound) {
        // Base case
        if (node == nullptr) {
            return true;
        }

        // Check if the current node's value is strictly within the required range
        if (node->val <= lower_bound || node->val >= upper_bound) {
            return false;
        }

        bool is_left_valid = _validate(node->left, lower_bound, node->val);
    
        if (!is_left_valid) {
            return false;
        }


        bool is_right_valid = _validate(node->right, node->val, upper_bound);

        return is_right_valid;
    }

    bool isValidBST(TreeNode* root) {
        return _validate(root, INT_MIN, INT_MAX);
    }
};
