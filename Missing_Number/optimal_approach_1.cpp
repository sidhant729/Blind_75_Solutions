// Problem Link -> https://leetcode.com/problems/missing-number/description/


class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // To Find Total Sum We Use The Formula -> N*N+1/2;
        int totalSum = (nums.size() * (nums.size()+1))/2;
        // Decrease The vals in Nums from The total 
        for(auto it : nums) totalSum -= it;
        // left Out will be the required result
        return totalSum;
    }
};

// T.C. - O(N)
// S.C. - O(1)