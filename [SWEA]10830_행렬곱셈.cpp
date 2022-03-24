#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define mod 1000

using namespace std;


long long  n, b;
long long a[5][5];
long long temp[5][5], result[5][5];

void mat_mult(long long x[5][5], long long y[5][5])
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < n; k++)
				temp[i][j] += x[i][k] * y[k][j];

			temp[i][j] %= mod;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			x[i][j] = temp[i][j];

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> b;
	memset(result, 0, sizeof(result));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
		result[i][i] = 1;
	}
	
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			mat_mult(result, a);
		}
		mat_mult(a, a);
		b /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << result[i][j] << " ";

		cout << "\n";
	}

}