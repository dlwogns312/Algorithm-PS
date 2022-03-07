#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int arr[1000001];
int n;
vector<int> result;
int num = 0;

int find(int target,int num)
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
	return e ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int>v;

	cin >> n;

	cin >> arr[0];
	v.push_back(0);
	result.push_back(arr[0]);
	num++;

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > result[num - 1])
		{
			v.push_back(num);
			result.push_back(arr[i]);
			num++;
		}
		else
		{
			int idx = find(arr[i],num);
			result[idx] = arr[i];
			v.push_back(idx);
		}
	}
	
	cout << num << "\n";
	vector<int>save(num);

	for (int i = v.size() - 1; i >= 0&&num; i--)
	{
		if (num - 1 == v[i])
		{
			save[num - 1] = arr[i];
			num--;
		}
	}

	for (int i = 0; i < save.size(); i++)
		cout << save[i] << " ";
	cout << "\n";
	return 0;

}