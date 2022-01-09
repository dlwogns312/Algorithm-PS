#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
#include <stack>
using namespace std;

#define mod 1000000007

long long ans[54][54];
long long arr[54][54];

void mult(long long a[54][54], long long b[54][54], int n, int k)
{
	long long ret[54][54] = { 0, };

	for (int i = 0; i < k + 2; i++)
	{
		for (int j = 0; j < k + 2; j++)
		{
			for (int x = 0; x < k + 2; x++)
				ret[i][j] = (ret[i][j] + a[i][x] * b[x][j]) % mod;
		}
	}

	for (int i = 0; i < 54; i++)
		for (int j = 0; j < 54; j++)
			a[i][j] = ret[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n, k;
	cin >> k >> n;

	for (int i = 0; i < k + 2; i++)
		ans[i][i] = 1;

	for (int i = 0; i < k + 2; i++)
		for (int j = 0; j <= i; j++)
			arr[i][j] = 1;

	n--;

	while (n)
	{
		if (n % 2 == 1)
			mult(ans, arr, n, k);
		mult(arr, arr,n,k);
		n /= 2;
	}
	
	long long result = 0;
	for (int i = 0; i < k + 2; i++)
		result = (result + ans[k + 1][i]) % mod;

	cout << result << "\n";
}