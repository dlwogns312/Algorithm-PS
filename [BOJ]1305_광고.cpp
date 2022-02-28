#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int fail[1000000] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string arr;
	cin >> n;
	cin >> arr;

	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && arr[i] != arr[j])
			j = fail[j - 1];
		if (arr[i] == arr[j])
			fail[i] = ++j;
	}

	cout << n -fail[n-1] << "\n";


	return 0;
}