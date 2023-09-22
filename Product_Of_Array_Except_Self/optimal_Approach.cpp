// Problem Link -> https://leetcode.com/problems/product-of-array-except-self/description/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // Find The Size of The array
        int n = nums.size();

        // Initialize the result array;
        vector<int>res(n, 0);
        int currEle = 1;
        for(int i = 0; i < n; i++)
        {
            // At the present Index Take the product of element before ith element that is excluding the current iteration
            res[i] = currEle;
            currEle *= nums[i];
        }
        currEle = 1;
        for(int i = n-1; i >= 0; i--)
        {
            // At the present Index Take the product of elements after the ith Index thus leaving behind current Element.
            res[i] *= currEle;
            currEle *= nums[i];
        }        
        return res;
    }
};


// T.C. - O(n) (Overall it takes o(2n) T.C. while the better approach takes o(3n) time complexity)
// S.C. - O(n) (overall it takes o(1) space complexity while the better approach takes O(3n) space complexity)
