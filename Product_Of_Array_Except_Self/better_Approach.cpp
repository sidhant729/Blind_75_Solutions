// Problem Link -> https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // Find The Size of The array
        int n = nums.size();

        // Create Two Arrays One to Store Prefix and Other for Suffix;
        vector<int>pref(n, 0);
        vector<int>suf(n, 0);

        //let the first element of the array be 1
        pref[0] = 1;
        for(int i = 1; i < n; i++)
        {
            // At the present Index Take the product of element before ith element that is excluding the current iteration
            pref[i] = pref[i-1]*nums[i-1];
        }

        // Initialize The Suffix Array;
        suf[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
        {
            // At the present Index Take the product of elements after the ith Index thus leaving behind current Element.
            suf[i] = suf[i+1]*nums[i+1];
        }

        // Initialize the result array;
        vector<int>res(n, 0);

        for(int i = 0; i < n; i++)
        {
            // Calculate the product;
            res[i] = pref[i] *suf[i];
        }

        // return the resultant array;
        return res;
    }
};

// T.C. - O(n)
// S.C. - O(n)