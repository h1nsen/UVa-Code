// UVa 383 -- Shipping Routes
// Username: h1nsen
// Time: .009 seconds
// C++11
// Algorithm: Floyd Warshall APSP
// This file differs from my original submission in that it uses APSP instead of repeated BFS
#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int dp[32][32];
unordered_map<string,int> mapping;
int main()
{
	int cases;
	cin >> cases;
	int l =1;
	cout << "SHIPPING ROUTES OUTPUT\n";
	while(cases--)
	{
		for(int i =0; i < 32; ++i)fill(begin(dp[i]),end(dp[i]),100000);
		mapping.clear();
		int m,n,p;
		cin >> m >> n >> p;
		for(int i =0; i < m; ++i)
		{
			string line;
			cin >> line;
			mapping[line]=i;
			dp[i][i] = 0;
		}
		for(int i =0 ; i < n; ++i)
		{
			string src,dst;
			cin >> src >> dst;
			dp[mapping[src]][mapping[dst]] = 1;
			dp[mapping[dst]][mapping[src]] = 1;
		} 
		// floyd-warshall APSP 
		for(int k = 0; k < n; ++k)
		{
			for(int i =0 ; i <n; ++i)
			{
				for(int j =0 ; j < n; ++j)
				{
					if(dp[i][k] + dp[k][j] < dp[i][j])
						dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
		cout << "\nDATA SET  " << l++ << "\n\n";		
		for(int i = 0; i < p; ++i)
		{
			int price;
			string src,dst;
			cin >> price >> src >> dst;
			int val = dp[mapping[src]][mapping[dst]];
			if(val == 100000)
				cout << "NO SHIPMENT POSSIBLE\n";
			else
				cout << "$" <<val * price * 100 << "\n";
		}
	}
	cout << "\nEND OF OUTPUT\n";
}