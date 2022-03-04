#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define min(a,b) a<b?a:b
#define INF 999999999

using namespace std;

int n;
int arr[17][17];
int dp[1 << 16][17] = { 0 ,};
int visited = 0;
int check;

int find(int bit, int now)
{
	bit |= (1 << now);
	
	if (dp[bit][now])
		return dp[bit][now];
	if (bit == check)
	{
		if (arr[now][0])
			return arr[now][0];
		else
			return  INF;
	}
	
	int ret = INF;

	for (int i = 0; i < n; i++)
	{
		if (arr[now][i] && !(bit & (1 << i)))
			ret = min(ret, find(bit, i) + arr[now][i]);
	}

	return dp[bit][now] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	check=(1 << n) - 1;

	cout << find(0,0)<< "\n";
	return 0;
}