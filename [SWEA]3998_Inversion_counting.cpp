#include<iostream>
#include<vector>
#include<memory>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
long long result;
vector<int> v;
vector<int>temp;

void merge(int start, int mid, int end)
{
	int l = start, m = mid+1, idx = start;

	while (l <= mid && m <= end)
	{
		if (v[l] < v[m])
			temp[idx++] = v[l++];
		else if (v[l] > v[m])
		{
			result += mid - l+1;
			temp[idx++] = v[m++];
		}
		else
			temp[idx++] = v[m++];
	}

	while (l <= mid)
		temp[idx++] = v[l++];
	while (m <= end)
		temp[idx++] = v[m++];

	for (int i = start; i <= end; i++)
		v[i] = temp[i];
}

void merge_sort(int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end)
	{
		merge_sort(start, mid);
		merge_sort(mid+1 , end);
		merge(start, mid, end);
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		result = 0;
		v.resize(n);
		temp.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		merge_sort(0, n-1);

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}