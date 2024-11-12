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

vector<int>floydWarshall(int n, vector<vector<int>>&edges, int start)
{
    vector<vector<int>>mat(n, vector<int>(n, INT_MAX));
    for(int i = 0; i<n; i++)
    {
        mat[i][i] = 0;
    }
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        mat[u][v] = w;
        mat[v][u] = w;  
    }
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX && mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    return mat[start];
}

int main()
{
    int n = 5;
    vector<vector<int>>edges = {{0, 1, 4}, {1, 4, 1}, {4, 3, 3}, {3, 2, 2}, {2, 1, 5}, {2, 4, 3}};
    int start = 0;

    vector<int>ans = floydWarshall(n, edges, start);
    for(int i = 0 ; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }    
    cout<<endl;

    return 0;
}