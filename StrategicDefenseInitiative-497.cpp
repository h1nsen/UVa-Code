// UVa 497 Strategic Defense Initiative
// Time 0.015 seconds
// C++11
// Username: h1nsen
// Algorithm: Dynamic Programming, Longest Increasing Subsequence O(n^2)
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	bool print_blank = false;
	int cases;
	scanf("%d",&cases);
	string line;
	getchar(); // '\n' buffer
	getchar(); // blank line
	vector<int> nums;
	char buf[100000];
	while(cases--)
	{
			if(print_blank)
				printf("\n");
			print_blank=true;
			nums.clear();
			while(gets(buf) && strcmp(buf,""))
			{
				int v = atoi(buf);
				nums.push_back(v);
			}
			vector<int> lis(nums.size(),1),parent(nums.size(),-1);
			int index_max = 0;
			for(int i =1; i< nums.size(); ++i)
			{
				for(int j=0;j < i; ++j)
				{
					if(nums[i] > nums[j] && lis[i] <= lis[j]+1)
					{
						lis[i] = lis[j]+1;
						parent[i]=j;
					}
				}
			}
		
			for(int i =0 ; i < nums.size(); ++i)
			{
				if(lis[i] > lis[index_max]) index_max=i;
			}
			printf("Max hits: %d\n",lis[index_max]);
			int i =0;
			while(index_max != -1)
			{
				lis[i++] = nums[index_max];
				index_max = parent[index_max];
			}
			for(int j =i-1 ; j >=0; --j)
			{

				printf("%d",lis[j]);
				if(j!=0)
					printf("\n");
	
			}
			printf("\n");
		}
	return 0;
}