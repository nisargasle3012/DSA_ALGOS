#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void algo(vector<int>&ans, unordered_map<int, vector<pair<int, int>>>&map, int start) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    ans[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int nodeDist = pq.top().first;
        pq.pop();
        for (auto neighbor : map[node]) 
        {
            int v = neighbor.first;
            int w = neighbor.second;

            if (w + ans[node] < ans[v]) 
            {
                ans[v] = w + ans[node];
                pq.push({ans[v], v});
            }
        }
    }
}

vector<int>dijkstras(int n, vector<vector<int>>&edges, int start)
{
    unordered_map<int, vector<pair<int, int>>>map;
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        map[u].push_back({v, w});
        map[v].push_back({u, w});
    }
    vector<int>ans(n, INT_MAX);
    algo(ans, map, start);

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>>edges = {{0, 1, 4}, {1, 4, 1}, {4, 3, 3}, {3, 2, 2}, {2, 1, 5}, {2, 4, 3}};
    int start = 0;

    vector<int>ans = dijkstras(n, edges, start);
    for(int i = 0 ; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }    
    cout<<endl;

    return 0;
}