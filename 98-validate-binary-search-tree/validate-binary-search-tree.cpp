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
    bool check(TreeNode* node, long long minValue, long long maxValue){
        if(node==nullptr){
            return true; 
        }
        if(node->val>minValue && node->val<maxValue){
            return (check(node->left, minValue, node->val) && check(node->right, node->val, maxValue)); 
        }
        else{
            return false; 
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX); 
    }
};