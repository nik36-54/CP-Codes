#include<bits/stdc++.h>
using namespace std;

void bfs(int n,vector<int>& adj,int src)
{
    vector<bool> vis(n,false);
    vis[src]=true;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<< u <<" ";
        
        for(auto x:adj[u])
        {
            if(!vis[x])
            {
                vis[x]=true;
                q.push(x);
            }
        }
    }
    return;
}

int main()
{
    // n - no of vertices , m - no of edges
    int n,m;
    cin>> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(n,adj,0);

    return 0;
}