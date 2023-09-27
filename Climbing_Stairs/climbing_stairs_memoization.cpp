// Problem Link -> https://leetcode.com/problems/climbing-stairs/description/

class Solution {
private:
    int climbStairsHelper(int n, vector<int>& memo)
    {
        if(n <= 2) return n;

        if(memo[n] != -1) return memo[n];

        return memo[n] = climbStairsHelper(n-1, memo) + climbStairsHelper(n-2, memo);
    }
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return climbStairsHelper(n, memo);
    }
};

// T.C. - O(n)
// S.C. - O(n)

// T.C - 


