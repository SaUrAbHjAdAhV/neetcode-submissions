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
    pair<int,bool> checkBalanced(TreeNode* root){
        if(root == nullptr){
            return {0,true};
        }
        pair<int,bool> left = checkBalanced(root->left);
        pair<int,bool> right = checkBalanced(root->right);
        if(left.second == false || right.second == false){
            return {1+max(left.first,right.first), false};
        }
        if(abs(left.first-right.first) > 1){
            return {1+max(left.first,right.first), false};
        }
        return {1+max(left.first,right.first), true};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans;
        ans = checkBalanced(root);
        return ans.second;
    }
};
