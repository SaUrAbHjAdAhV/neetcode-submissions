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

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == nullptr && q == nullptr){
//             return true;
//         }
//         if(p != nullptr && q == nullptr){
//             return false;
//         }
//         if(p == nullptr && q != nullptr){
//             return false;
//         }

//         queue<TreeNode*> q1,q2;
//         q1.push(p);
//         q2.push(q);
//         while(!q1.empty() && !q2.empty()){
//             int size1 = q1.size();
//             int size2 = q2.size();
//             if(size1 != size2){
//                 return false;
//             }
//             for(int i = 0; i < size1; i++){
//                 TreeNode* node1 = q1.front();
//                 TreeNode* node2 = q2.front();
//                 if(node1-> val != node2-> val){
//                     return false;
//                 }
//                 q1.pop();
//                 q2.pop();
//                 if(node1->left != nullptr && node2->left != nullptr){
//                     q1.push(node1->left);
//                     q2.push(node2->left);
//                 }
//                 else if(node1->left == nullptr && node2->left != nullptr){
//                     return false;
//                 }
//                 else if(node1->left != nullptr && node2->left == nullptr){
//                     return false;
//                 }
//                 if(node1->right != nullptr && node2->right != nullptr){
//                     q1.push(node1->right);
//                     q2.push(node2->right);
//                 }
//                 else if(node1->right == nullptr && node2->right != nullptr){
//                     return false;
//                 }
//                 else if(node1->right != nullptr && node2->right == nullptr){
//                     return false;
//                 }
//             }
//         }
//         if(q1.empty() && q2.empty()){
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if(p != nullptr && q != nullptr && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else{
            return false;
        }
    }
};