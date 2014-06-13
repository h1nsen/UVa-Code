// UVa 315 -- Network
// Username: h1nsen
// C++11
// Time: .039 seconds
// Algorithm: Tarjan's Articulation Points

#include <numeric>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
int dfs_num[100], dfs_low[100];
int artic[100];
int parent[100];
unordered_map<int,vector<int>> adj;
int root_count=0;
void artic_points(int i,int ct)
{
	dfs_num[i] = dfs_low[i] = ct++;
	for(const auto& x : adj[i])
	{
		if(dfs_num[x] == -1)
		{
			parent[x] = i;
			artic_points(x,ct);
			if(dfs_low[x] >= dfs_num[i] && parent[i] != -1)
			{
			//	++total_artic;
				artic[i]=1;
			}
			if(parent[i]==-1)
				++root_count;
			if(root_count > 1 && parent[i] == -1)
				artic[i]=1;
			dfs_low[i] = min(dfs_low[i],dfs_low[x]);
		}
		else
		{
			if(x != parent[i])
			{
				dfs_low[i]= min(dfs_low[i],dfs_num[x]);
			}
		}
	}
}
int main()
{
//	ios_base::sync_with_stdio(false);
	int n,cur_root=-1;
	scanf("%d",&n);
	string line;
	while(true)
	{
		cur_root=-1;
		root_count=0;
		adj.clear();
		memset(artic,0,sizeof artic);
		memset(dfs_num,-1,sizeof dfs_num);
		memset(dfs_low,-1,sizeof dfs_low);
		memset(parent,-1,sizeof parent);
		getline(cin,line);
		if(line == "0")break;
		while(getline(cin,line))
		{
			if(line == "0")break;

		
		stringstream ss(line);
		int nxt,part;
		
		ss >> nxt;
		if(cur_root == -1)
			cur_root = nxt;
		while(ss >> part)
		{
			adj[nxt].push_back(part);
			adj[part].push_back(nxt);
		}
		}
		//artic_points(cur_root,0);
		int p = 0;
		artic_points(cur_root,0);
		cout << accumulate(artic,artic + 100,0) << "\n";
	}
	return 0;
}