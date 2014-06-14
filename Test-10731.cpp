// UVa 10731 -- Test
// Username: h1nsen
// Time: .032 seconds
// C++11
// Algorithm: Tarjan's SSC
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
vector<string> configs;
unordered_set<char> corpus;
unordered_set<int> in_stack;
vector<int> ssc_stack;
int matr[30][30];
int dfs_num[30],dfs_low[30];
int vis[30];
int num = 0;
void tarjan_ssc(int u)
{
	dfs_num[u] = dfs_low[u] = num++;
	ssc_stack.push_back(u); in_stack.insert(u);
	for(int i = 0; i < 26; ++i)
	{
		if(matr[u][i] && dfs_num[i] == -1)
		{
			tarjan_ssc(i);
		}
		 if(matr[u][i] && in_stack.find(i) != in_stack.end())
		{
			dfs_low[u] = min(dfs_low[u],dfs_low[i]);
		}
	}
	if(dfs_num[u] == dfs_low[u])
	{
		stringstream ss;
		while(!ssc_stack.empty() && ssc_stack.back() != u)
		{
			ss << (char) (ssc_stack.back() + 'A');
			in_stack.erase(ssc_stack.back());
			ssc_stack.pop_back();
		}		
		ss << (char) (ssc_stack.back() + 'A'); in_stack.erase(ssc_stack.back()); ssc_stack.pop_back();
		string line = ss.str();
		sort(line.begin(),line.end());
		configs.push_back(line);
	}
}


int main()
{
	int n;
	bool blank = false;
	while(cin >> n && n)
	{
		num=0;
		if(blank) cout << endl;
		blank=true;
		configs.clear();
		corpus.clear();
		in_stack.clear();
		ssc_stack.clear();
		memset(matr,0,sizeof matr);
		memset(dfs_num,-1,sizeof dfs_num);
		memset(dfs_low,-1,sizeof dfs_low);
		char c1,c2,c3,c4,c5,c6;
		for(int i =0; i < n; ++i)
		{
			cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
			if(c1 != c6)matr[c6-'A'][c1-'A'] = 1;
			if(c2 != c6)matr[c6-'A'][c2-'A'] = 1;
			if(c3 != c6)matr[c6-'A'][c3-'A'] = 1;
			if(c4 != c6)matr[c6-'A'][c4-'A'] = 1;
			if(c5 != c6)matr[c6-'A'][c5-'A'] = 1;
			corpus.insert(c1-'A');
			corpus.insert(c2-'A');
			corpus.insert(c3-'A');
			corpus.insert(c4-'A');
			corpus.insert(c5-'A');
			corpus.insert(c6-'A');
		}
		for(const auto& x : corpus)
		{
			if(dfs_num[x] == -1)
				tarjan_ssc(x);
		}
		sort(configs.begin(),configs.end());
		for(int i =0 ; i < configs.size(); ++i)
		{
			cout << configs[i][0];
			for(int q =1; q < configs[i].length(); ++q)
			{
				cout << " " << configs[i][q];
			}
			cout << endl;
		}


	}
	return 0;
}