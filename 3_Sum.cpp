// Problem Link - https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // create a 2D Array to store the result
        vector<vector<int>>ans;
        // Sort The array
        sort(nums.begin(), nums.end());

        // Iterate Over The Array;
        for(int i = 0; i < nums.size(); i++)
        {
            // If current Element is Same as prev then, skip the iteration
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // Take two pointers low and high.
            int low = i + 1;
            int high = nums.size() - 1;

            while(low < high)
            {
                // Find The Summation
                int sum = nums[i];
                sum += nums[low];
                sum += nums[high];

                // If sum > 0 then decrease high 
                if(sum > 0)
                {
                    high--;
                }
                // else if sum < 0 then increase the low
                else if(sum < 0)
                {
                    low++;
                }
                else
                {
                    // Store In the Array;
                    vector<int>res = {nums[i], nums[low], nums[high]};
                    // Push In The 2D Array;
                    ans.push_back(res);
                    // Increament low and high
                    low++;
                    high--;
                    // If prev Elements are same as current then skip current iteration
                    while(low < high && nums[low] == nums[low - 1]) low++;
                    while(low < high && nums[high] == nums[high + 1]) high--;
                }
            }
        }
        // return the result
        return ans;
    }
};

// T.C. - O(n log(n));
// S.C. - O(k) where k is the valid triplets