//UVa 483 -- Word Scramble
// Username: h1nsen
// Time: .013 seconds
// C++11
// Algorithm: Ad-Hoc straightforward, reverse the strings.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string line;
	while(getline(cin,line))
	{
		stringstream ss(line);
		string nxt;
		ss >> nxt;
		reverse(nxt.begin(),nxt.end());
		cout << nxt;
		while(ss >> nxt)
		{
			cout << " ";
			reverse(nxt.begin(),nxt.end());
			cout << nxt;
		}
		cout << endl;
	}
	return 0;
}