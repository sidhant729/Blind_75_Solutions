// Problem Link -> https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/


class Solution {
private:
    void inOrder(TreeNode* root, vector<int>& storeEle){
        if(!root) return;
        inOrder(root->left, storeEle);
        storeEle.push_back(root->val);
        inOrder(root->right, storeEle);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>storeEle;
        inOrder(root, storeEle);
        return storeEle[k-1];
    }
};

// Time Complexity -> O(n);
// Space Complexity -> O(n);