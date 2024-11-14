#include<iostream>
#include<bits/stdc++.h>

using namespace std;

static bool comp(vector<int>a, vector<int>b)
{
    return a[2] < b[2];
}

void makeSet(vector<int>&parent, vector<int>&rank, int n)
{
    for(int i = 0; i<n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>&parent, int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank)
{       
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] > rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

vector<vector<int>> kruskals(int n, vector<vector<int>>&graph)
{
    vector<vector<int>>ans;
    sort(graph.begin(), graph.end(), comp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    for(auto edge : graph)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (findParent(parent, u) != findParent(parent, v)) 
        {
            ans.push_back({u, v, w});
            unionSet(u, v, parent, rank);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>>graph = {{0, 1, 1}, {1, 2, 6}, {0, 3, 3}, {3, 4, 1}, {1, 4, 5}, {2, 4, 2}, {1, 3, 3}};
    int n = 5;

    vector<vector<int>>ans = kruskals(n, graph);
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i][0]<<"->"<<ans[i][1]<<":"<<ans[i][2]<<endl;
    }
    return 0;
}