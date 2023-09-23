// Problem Link - // Problem Link -> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int min_ele = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            min_ele = min(min_ele, nums[i]);
        }

        return min_ele;
    }
};

// T.C. - O(N);
// S.C. - O(1)