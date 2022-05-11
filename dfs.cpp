#include<bits/stdc++.h>
using namespace std;
bool vis[(int)(1e5+1)];
// graph use
void dfs(int src)
{
   vis[src] = true;  
   for(int u:adj[src])
   {
   	if(!vis[u])
   	dfs(u);
   }

}

// tree use
void dfs(int child,int parent)
{
	v[child]=parent; 
	for(int i:v[child])
	{
		if(i!=v[child])
			dfs(i,child);
	}
}