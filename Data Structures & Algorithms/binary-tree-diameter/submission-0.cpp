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
    pair<int,int> checkDia(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int,int> left = checkDia(root->left);
        pair<int,int> right = checkDia(root->right);
        return {1+max(left.first,right.first), max({left.first+right.first,right.second,left.second})};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> diameter;
        diameter = checkDia(root);
        return diameter.second;
    }
};
