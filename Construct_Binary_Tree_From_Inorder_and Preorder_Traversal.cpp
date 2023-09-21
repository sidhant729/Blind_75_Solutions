// Problem Link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd
    , vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp)
    {
        // Base Case
        if(preStart > preEnd || inStart > inEnd) return NULL;

        // Create The Root
        // Since preorder is Left->Root->Right, so first Element is always root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find The root Index In The Map
        int rootInd = mp[root->val];

        // No. Of Elements in Left;
        int ele_in_left = rootInd - inStart;

        // Insert The root->left
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + ele_in_left, inorder, inStart, rootInd - 1, mp);

        // Insert The root->right
        root->right = buildTreeHelper(preorder, preStart + ele_in_left + 1, 
        preEnd, inorder, rootInd + 1, inEnd, mp);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        // Create a Map of TreeNode* and int to Store Node and Its Index
        map<int,int>mp;

        // Store The Inorder Array elements along With Index In The Map.
        for(int ind = 0; ind < inorder.size(); ind++)
        {
            mp[inorder[ind]] = ind;
        }

        // Call The Helper Function Which Creates The Tree.
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};

T.C -> O(N)
S.C -> O(N)