// Problem Link -> https://practice.geeksforgeeks.org/problems/number-of-provinces/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<int>adjList[])
    {
        vis[node] = 1;
        
        for(auto it : adjList[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adjList);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) 
    {
       vector<int>adjList[V];
       
       for(int i = 0; i < V; i++)
       {
           for(int j = 0; j < V; j++)
           {
               if(i != j && adj[i][j] == 1)
               {
                   adjList[i].push_back(j);
               }
           }
       }
       
       // Create A Visited Array to keep track of the visited Vertices/Nodes.
       
       vector<int>vis(V, 0);
       
       // Perform DFS Operation for Each Of The Nodes.
       
       // Take a variable to keep track total Components.
       int totalComponents = 0;
       for(int i = 0; i < V; i++)
       {
           if(!vis[i])
           {
               totalComponents++;
               dfs(i, vis, adjList);
           }
       }
       
       return totalComponents;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends

// T.C. - O(V^2)
// S.C. - O(v^2)