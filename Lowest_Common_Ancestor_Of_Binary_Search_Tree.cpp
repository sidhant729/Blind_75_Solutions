// Problem Description -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->val < p->val && curr->val < q->val){
                curr = curr->right;
            }else if(curr->val > p->val && curr->val > q->val){
                curr = curr->left;
            }else{
                return curr;
            }
        }
        return curr;
    }
};

// Time Complexity -> O(log n);
