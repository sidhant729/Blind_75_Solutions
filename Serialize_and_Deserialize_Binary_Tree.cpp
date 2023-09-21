// Problem Link -> https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        // Edge Case 
        if(!root) return "";

        string str = "";
        
        // create a Queue of TreeNode* type to perform level order traversal
        queue<TreeNode*>q;

        // Push The root In The Queue
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(curr->val) + ',');
            }
            if(curr != NULL)
            {
                // If curr is Not null, push its left and right in queue
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // return the resultant string
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        // If data is empty return NULL;
        if(data == "") return NULL;
        
        // stringstream allows string to be iterated as objects
        stringstream s(data);
        string str;
        getline(s,str,',');

        // Create A root;
        TreeNode* root = new TreeNode(stoi(str));
        // Create a queue of TreeNode* type to perform level order Traversal
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            getline(s, str, ',');
            if(str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Time Complexity = O(N).
// Space Complexity = O(N).