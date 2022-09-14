#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n;
string result;

void dfs(int level, string str)
{
	if (result!="")
		return;

	int tmp = str.length();

	//Check whether it is bad sequence
	for (int i = 1; i <= tmp / 2; i++)
		if (str.substr(tmp - i, i) == str.substr(tmp - 2 * i, i))
			return;

	if (level == n)
	{
		result = str;
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		dfs(level+1,str+"1");
		dfs (level + 1,str + "2");
		dfs( level + 1,str+"3");
	}
}
int main()
{
	cin >> n;
	dfs(0, "");

	cout << result;
}