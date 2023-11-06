// Problem Link -> https://www.codingninjas.com/studio/problems/graph-valid-tree_1376618?topList=top-graphs-interview-questions&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
bool dfs(int node, int parent, vector<int>adjList[], vector<int>& vis)
{
    vis[node] = 1;
    bool isValid = false;
    for(auto it : adjList[node])
    {
        if(!vis[it])
        {
            if(dfs(it,node, adjList, vis)) isValid = true;
        }
        else if(it != parent) isValid = true;
    }
    return isValid;
}
bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int>vis(n, 0);
    int islands = 0;
    vector<int>adjList[n];
    for(auto it : edges)
    {
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            islands++;
            if(dfs(i, -1, adjList, vis)) return false;
        }
    }
    if(islands > 1) return false;
    return true;
}