#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int temp;
	int result = 0;
	char str[10];

	while (n--)
	{
		cin >> str;
		if (!strcmp(str,"add"))
		{
			cin >> temp;
			result |= (1 << (temp - 1));
		}
		else if (!strcmp(str, "remove"))
		{
			cin >> temp;
			result |= (1 << (temp - 1));
			result -= (1 << (temp - 1));
		}
		else if (!strcmp(str, "check"))
		{
			cin >> temp;
			if (result & (1 << (temp - 1)))
				cout << 1;
			else
				cout << 0;
			cout << "\n";
		}
		else if (!strcmp(str, "toggle"))
		{
			cin >> temp;
			if (result & (1 << (temp - 1)))
				result -= (1 << (temp - 1));
			else
				result |= (1 << (temp - 1));
		}
		else if (!strcmp(str, "all"))
		{
			result = (1 << 20) - 1;
		}
		else
			result = 0;

	}
	return 0;

}