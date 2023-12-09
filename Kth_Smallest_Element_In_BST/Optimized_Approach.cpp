// Problem Link -> https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode * curr = root;
        int ans;
        int count = 0;
        while(curr){
            
            if(!curr->left){
                count++;
                if(count == k){
                ans =  curr->val;
            }
                curr = curr->right;
            }
            else{
                TreeNode * prev = curr->left;
                while(prev->right && prev->right!=curr)
                    prev = prev->right;
                
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    count++;
                    if(count==k){
                        ans = curr->val;
                    }
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// T.C. - O(N)
// S.C. - O(1)