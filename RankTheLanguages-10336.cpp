// UVa 10336 Rank the Languages
// username: h1nsen
// C++11
// Time: .778 seconds
// Algorithm: Flood-Fill DFS + Sorting

#include <vector>
#include <functional>
#include <utility>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//int languages[27];
vector<pair<int,int>> languages(27);
int seen[10000][10000];
char map[10000][10000];
char buf[10000];
char cur;
int h,w;
void visit(int x, int y)
{
	seen[x][y]=true;
	for(int i = -1; i <= 1; ++i)
	{
		for(int j =-1; j <= 1; ++j)
		{
			if(!((j != 0 && i == 0) || (i != 0 && j == 0)))
				continue;
			int dx = x+i;
			int dy = y+j;
			if(dx < 0 || dx >= h || dy < 0 || dy >= w || map[dx][dy] != cur || seen[dx][dy])
				continue;
			visit(dx,dy);
		}
	}
}
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first > b.first) return true;
	else if(a.first < b.first) return false;
	return a.second < b.second;
}
int main()
{

	int N;
	scanf("%d",&N);
	int num=1;
	while(N--)
	{
		memset(seen,false,sizeof seen);
		for(int i =0; i < 26; ++i)languages[i]= make_pair(0,i);
		scanf("%d %d",&h,&w);
		getchar();
		for(int i =0 ; i < h; ++i)
		{
			gets(buf);
			for(int j =0 ; j < w; ++j)
				map[i][j] = buf[j];
		}
		for(int i=0; i < h; ++i)
		{
			for(int j =0 ;j < w; ++j)
			{
				if(!seen[i][j])
				{
					cur = map[i][j];
					visit(i,j);
					++languages[cur-'a'].first;
				}
			}
		}
		printf("World #%d\n",num++);
		sort(languages.begin(),languages.end(),cmp);
		for(int i =0; i < 26; ++i)
		{
			if(languages[i].first)
			{
				printf("%c: %d\n",(char)languages[i].second+'a',languages[i].first);
			}
			else break;
		}

	}
	return 0;
}