#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int arr[1000];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int max = 1;

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				if (max < dp[i])
					max = dp[i];
			}
		}
	}

	vector <int> result;
	cout << max << "\n";
	for (int i = n - 1; i >= 0; i--)
	{
		if (!max)
			break;
		if (dp[i] == max)
		{
			result.push_back(arr[i]);
			max--;
		}
	}
	
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
	cout << "\n";
	return 0;

}