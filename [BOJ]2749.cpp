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

int arr[1500010];

void mult()
{
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 0; i < 1500000; i++)
		arr[i + 2] = (arr[i + 1] + arr[i]) % mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	long long n;
	cin  >> n;

	mult();
	cout << arr[n % 1500000] << "\n";
}