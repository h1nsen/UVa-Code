// UVa 231 Testing the CATCHER
// User: h1nsen
// Time: 0.009 seconds
// Dynamic Programming, Longest Decreasing Subsequence

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int c=1;
	while(true)
	{
		cin >> n;
		if(n == -1) break;
		if(c > 1 ) cout << endl;
		vector<int> vals;
		while(true)
		{
			vals.push_back(n);
			cin >> n;
			if(n == -1)	break;
		}
		vector<int> base(vals.size(),1);
		for(int i = 1; i < base.size(); ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(vals[j] >= vals[i])
				{
					base[i] = max(base[i],base[j]+1);
				}
			}
		}
		int m = 1;
		for(const auto & x : base) m = max(m,x);
		cout << "Test #" << c++ << ":\n  maximum possible interceptions: " << m;
		cout << endl;
	}
	// your code goes here
	return 0;
}