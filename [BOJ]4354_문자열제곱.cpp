#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int fail[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string arr;
	
	int test = 10;

	while (test--)
	{
		cin >> arr;
		int n = arr.length();
	
		memset(fail, 0, sizeof(fail));
		if (arr[0] == '.')
			break;
		int result=0;
		int i, j;
		for ( i = 1, j = 0; i < n; i++)
		{
			if (j > 0 && arr[i] != arr[j])
			{
				j = fail[j - 1];
			}
			if (arr[i] == arr[j])
				fail[i] = ++j;
		}

		if (n % (n - fail[n - 1]))
			result = 1;
		else
			result = n / (n - fail[n - 1]);
		cout << result << "\n";

	}
	return 0;
}