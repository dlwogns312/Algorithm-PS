#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int arr[1000000];
vector<int> result;
int num = 0;

int find(int target, int num)
{
	int s = 0, e = num;
	int m;

	while (e > s)
	{
		m = (s + e) / 2;
		if (result[m] < target)
			s = m + 1;
		else
			e = m;
	}
	return e;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	cin >> arr[0];
	result.push_back(arr[0]);
	num++;

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];

		if (arr[i] > result[num - 1])
		{
			result.push_back(arr[i]);
			num++;
		}
		else
		{
			int idx = find(arr[i], num);
			result[idx] = arr[i];
		}
	}

	cout << num << "\n";
	return 0;

}