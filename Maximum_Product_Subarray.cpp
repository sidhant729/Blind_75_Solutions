// Problem Link -> https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        // Initialize two variables :-
        // pref_mult - To Store the Prefix Multiplication
        // suff_mult - To Store the suffix Multiplication
        int pref_mult = 1;
        int suff_mult = 1;

        // maxProduct - To Store The maximum Product found.
        int maxProduct = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            pref_mult *= nums[i];
            maxProduct = max(maxProduct, pref_mult);
            if(pref_mult == 0) pref_mult = 1;
        }


        for(int i = nums.size() - 1; i >= 0; i--)
        {
            suff_mult *= nums[i];
            maxProduct = max(maxProduct, suff_mult);
            if(suff_mult == 0) suff_mult = 1;
        }
        
        return maxProduct;
    }
};

// T.C. - O(n)
// S.C - O(1)