// Problem Link -> https://leetcode.com/problems/top-k-frequent-elements/description/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // Create A Min Heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // Create a Map
        unordered_map<int,int>mp;

        // Store Elements In the Map
        for(auto it : nums) mp[it]++;
        // Push the elements in Heap
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }

        // Create a resultant Variable
        vector<int>res;
        //Empty While k is not equal to zero
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        // return res;
        return res;
    }
};

// T.C. - O(nlogk);
// S.C. - O(n + k);