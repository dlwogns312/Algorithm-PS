#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define MAX (1<<21)
#define MOD (1<<21)-1
#define INF 0x3f3f3f3f

using namespace std;
int n;
int arr[21][21];
int dp[21][MAX];

int d(int cur, int flag)
{
	if (cur >= n)
		return flag == (1 << n) - 1 ? 0 : INF;

	int& ret = dp[cur][flag];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (!(flag & (1 << i)))
			ret = min(ret, d(cur + 1, flag | (1 << i)) + arr[cur][i]);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	memset(dp, -1, sizeof(dp));

	int result = d(0, 0);

	cout << result << "\n";

	return 0;
}