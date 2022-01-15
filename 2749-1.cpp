#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
#include <stack>
using namespace std;

#define mod 1000000

int ans[2][1];
int arr[2][2] = { 0, };

void mult()
{
	int ret[2][1] = { 0, };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int x = 0; x < 2; x++)
				ret[i][j] += (arr[i][x] * ans[x][j]) % mod;
		}
	}

	ans[0][0] = ret[0][0];
	ans[0][1] = ret[0][1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n;
	cin  >> n;

	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;

	ans[0][0] = 1;
	ans[0][1] = 1;

	if (n == 1 || n == 2)
	{
		cout << 1 << "\n";
		return 0;
	}
	if (n >= 3)
	{
		n -= 2;
		while (n)
		{
			mult();
			n--;
		}
	}
	
	cout << ans[1][0] << "\n";
	
}