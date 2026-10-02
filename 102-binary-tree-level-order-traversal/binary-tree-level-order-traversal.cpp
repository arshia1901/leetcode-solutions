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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        queue<TreeNode*> q; 
        if(root==nullptr){
            return {};
        }
        q.push(root); 
        while(!q.empty()){
            int q_size = q.size(); 
            vector<int> temp;
            for(int i = 0; i<q_size; i++){
                TreeNode* node = q.front(); 
                q.pop(); 
                temp.push_back(node->val); 
                if(node->left!=nullptr){
                    // push left child in queue 
                    q.push(node->left); 
                }
                if(node->right!=nullptr){
                    //push right child in queue
                    q.push(node->right); 
                }
            }
            result.push_back(temp); 
        }
        return result; 
    }
};