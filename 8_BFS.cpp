#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bfs(vector<bool>&vis, vector<int>&ans, unordered_map<int, vector<int>>&map, int start) 
{
    queue<int> q;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        ans.push_back(vertex);
        for (int neighbor : map[vertex]) 
        {
            if (!vis[neighbor]) 
            {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

vector<int>bfs_order(int n, vector<pair<int, int>>&edges, int start)
{
    unordered_map<int, vector<int>>map;
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    vector<int>ans;
    vector<bool>vis(n, false);
    bfs(vis, ans, map, start);

    return ans;
}

int main()
{
    int n = 5;
    vector<pair<int, int>>edges = {{0, 1}, {1, 4}, {4, 3}, {3, 2}, {2, 1}};
    int start = 0;

    vector<int>ans = bfs_order(n, edges, start);
    for(int i = 0 ; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }    
    cout<<endl;

    return 0;
}



