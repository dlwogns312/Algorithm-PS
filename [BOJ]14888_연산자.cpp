#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
int total=0;
int n;
int num[4];
int arr[12];
int max_result, min_result;

void dfs(int plus, int minus, int div, int mult, int total_num, int temp)
{
	if (total_num == total)
	{
		max_result = max(max_result, temp);
		min_result = min(min_result, temp);
		return;
	}

	if (plus < num[0])
	{
		dfs(plus + 1, minus, div, mult, total_num + 1,temp+arr[total_num+1]);
	}

	if (minus < num[1])
	{
		dfs(plus, minus + 1, div, mult, total_num + 1, temp-arr[total_num+1]);
	}

	if (div < num[3])
	{
		dfs(plus, minus, div + 1, mult, total_num + 1, temp/arr[total_num+1]);
	}

	if (mult < num[2])
	{
		dfs(plus, minus, div, mult + 1, total_num + 1, temp*arr[total_num+1]);
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
		total += num[i];
	}
	max_result = INT_MIN;
	min_result = INT_MAX;


	dfs(0, 0, 0, 0, 0,arr[0]);

	cout << max_result << "\n";
	cout << min_result << "\n";
}