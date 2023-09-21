// Problem Link - https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Create A resultant Array
        vector<int>res;

        // Take a Map
        unordered_map<int,int>mp;

        // Run A Loop
        for(int ind = 0; ind < nums.size(); ind++)
        {
            int req_val = target - nums[ind];

            if(mp.find(req_val) != mp.end())
            {
                // push The indexes In The result Array;
                res = {mp[req_val],ind};
                break;
            }

            // Put The Current Value In The Map Along With Index.
            mp[nums[ind]] = ind;
        }
        // return the resultant Array
        return res;   
    }
};

// Time Complexity = O(n)
// Space Complexity = O(n)