// Problem Link -> https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // Take a xorr variable and iterator i.
        int xorr = 0;
        int i = 0;

        // Let A Case -> 3 0 1 (here size of nums vector is 4)

        // run a loop till nums.size() => 
        for(; i < nums.size(); i++)
        {
            // First Iteration -> xor = 0 ^ 0 ^ nums[i](3)
            // Second Iteration -> xor = 3 ^ 1 ^ 0 ( 0 ^ 0 = 0)(remove 0 (no use))
            // Third Iteration -> xor = 0 ^ 3 ^ 1 ^ 0 ^ 2 ^ 1 (1 ^ 1 == 0 && 0 ^ 0 == 0);
            xorr ^= i ^ nums[i];
        }
        // Left Out -> 3 ^ 2
        // Now 3 ^ 2 ^ 3 
        // Now left out = 2 (3 ^ 3) -> required ans
        return xorr ^ i;
    }
};





// T.C. - O(N)
// S.C. - O(1)