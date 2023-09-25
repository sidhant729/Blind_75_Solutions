// Problem Link -> https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        // Take a Left and right Pointers
        int left = 0;
        int right = height.size() - 1;
        // Initialize res as 0
        int res = 0;
        // Run a loop till left < right
        while(left < right)
        {
            // Find The Area  
            int dist = right - left;
            int minHeight = min(height[left], height[right]);

            int currArea = dist*minHeight;
            // If currArea > prevArea then update
            res = max(currArea, res);
            // If leftHeight < righHeight move right
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                // Else move left
                right--;
            }
        }
        // return the result
        return res;
    }
};

// T.C. - O(n)
// S.C. - O(1)