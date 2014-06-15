// UVa 146 -- ID Codes
// Username: h1nsen
// C++11
// Time: .015 seconds
// Algorithm: std::next_permutation() to form all possible IDs

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string line;
	string query;
	//vector<string> vals;
	while(getline(cin,line) && line != "#")
	{
		query = line;
		//sort(line.begin(),line.end());
		bool flag = false;
		string output = "";
		do
		{
			if(flag){ output= line ; break;}
			if(line == query) flag = true;
		}while(next_permutation(line.begin(),line.end()));
		if(output.length() > 0) cout << output << "\n";
		else
			cout << "No Successor\n";
		
	}
	return 0;


}