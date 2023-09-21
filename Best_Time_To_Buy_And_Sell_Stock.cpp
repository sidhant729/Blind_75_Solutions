// Problem Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/



class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        // let the max profit be 0.
        int max_profit = 0;

        // Take The first element as the curr minimum element.
        int curr_min = prices[0];
        
        // Run a loop
        for(int ind = 0; ind < prices.size(); ind++)
        {
            // Find The curr Profit;
            int curr_profit = prices[ind] - curr_min;

            // Check Whether curr_profit is max or not
            // If yes then max_profit = curr_profit;
            max_profit = max(max_profit, curr_profit);

            // If curr Ele is less than the curr_min 
            // make curr_min equal to curr element;
            curr_min = min(curr_min, prices[ind]);
        }
        // return the max profit obtained;
        return max_profit;
    }
};

// T.C. - O(N).
// S.C. - O(1)