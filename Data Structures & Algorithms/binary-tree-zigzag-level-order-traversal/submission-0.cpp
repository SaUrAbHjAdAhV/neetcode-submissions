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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q1;
        q1.push(root);  
        bool righttoleft = false;
        while(!q1.empty()){
            int size = q1.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left != nullptr){
                    q1.push(node->left);
                }
                if(node->right != nullptr){
                    q1.push(node->right);
                }
                if(righttoleft){
                    level[size-i-1] = node->val;
                }
                else{
                    level[i] = node->val;
                } 
            }
            righttoleft = !righttoleft;
            ans.push_back(level);
        }
        return ans;
    }
};