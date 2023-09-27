// Problem Link -> https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> tabulation(n+1, 0);
        // Edge Case
        if(n == 1 || n == 2 || n == 0) return n;

        tabulation[1] = 1;
        tabulation[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            tabulation[i] = tabulation[i-1] + tabulation[i-2];
        }
        return tabulation[n];
    }
};




// T.C. - O(n)
// S.C. - O(n) (better than memoization, since no space for recursive calls)