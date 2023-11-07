// Problem Link -> https://leetcode.com/problems/course-schedule/description/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = prerequisites.size();
        vector<int>Indegree(numCourses, 0);   

        vector<int>adjList[numCourses];

        for(auto it : prerequisites)
        {
            adjList[it[1]].push_back(it[0]);
            Indegree[it[0]]++;
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(Indegree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(auto it : adjList[curr])
            {
                Indegree[it]--;
                if(Indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        for(int i = 0; i < Indegree.size(); i++)
        {
            if(Indegree[i] != 0) return false;
        }
        return true;
    }
};