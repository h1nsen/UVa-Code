// UVa 383 -- Shipping Routes
// Username: h1nsen
// Time: .013 seconds
// Algorithm: BFS from every query node, could be improved by Floyd Warshall's APSP
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int,vector<int>> adjlist;
unordered_map<string,int> mapped;
unordered_map<int,int> dist;
int bfs(int source, int dest)
{
	queue<int> q;
//	visit[source] = true;
	q.push(source);
	dist[source]=0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(u == dest)
			return dist[u];
		for(const auto&  x : adjlist[u])
		{
			if(!dist.count(x))
			{
				dist[x] = dist[u] + 1;
				q.push(x);
			}
		}

	}
	return -1;


}
int main()
{
	int cases;
	cin >> cases;
	int l =1;
	cout << "SHIPPING ROUTES OUTPUT\n";
	while(cases--)
	{
		
		adjlist.clear();
		mapped.clear();
		int m,n,p;
		cin >> m >> n >> p;
		for(int i =0; i < m; ++i)
		{
			string line;
			cin >> line;
			mapped[line]=i;

		}
		for(int i =0 ; i < n; ++i)

		{
			string src,dst;
			cin >> src >> dst;
			adjlist[mapped[src]].push_back(mapped[dst]);
			adjlist[mapped[dst]].push_back(mapped[src]);
		}
		cout << "\nDATA SET  " << l++ << "\n\n";		
		for(int i = 0; i < p; ++i)
		{
			int price;
			string src,dst;
			cin >> price >> src >> dst;
			int val = bfs(mapped[src],mapped[dst]);
			if(val < 0)
				cout << "NO SHIPMENT POSSIBLE\n";
			else
				cout << "$" <<val * price * 100 << "\n";
			//memset(visit_time,0,sizeof visit_time);
			dist.clear();
		}
	}
	cout << "\nEND OF OUTPUT\n";
}