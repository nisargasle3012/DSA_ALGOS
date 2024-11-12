#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>bellmanFord(int n, vector<vector<int>>&edges, int start)
{
    vector<int>ans(n, INT_MAX);
    ans[start] = 0;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j<edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(ans[u] != INT_MAX && ans[u] + w < ans[v])
            {
                ans[v] = ans[u] + w;
            }
            if(ans[v] != INT_MAX && ans[v] + w < ans[u])
            {
                ans[u] = ans[v] + w;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (ans[u] != INT_MAX && ans[u] + w < ans[v]) 
        {
            cout << "Graph contains a negative-weight cycle"<<endl;
            return {};
        }
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>>edges = {{0, 1, 4}, {1, 4, 1}, {4, 3, 3}, {3, 2, 2}, {2, 1, 5}, {4, 2, 3}};
    int start = 0;

    vector<int>ans = bellmanFord(n, edges, start);
    for(int i = 0 ; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }    
    cout<<endl;

    return 0;
}
//Has different code for both directed and undirected graph