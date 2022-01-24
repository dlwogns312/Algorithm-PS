
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int w[200000], s[200000];
int n, k;

bool check(int val)
{
	int pivot = -1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < s[i]; j++)
		{
			pivot++;
			if (pivot == n)
				return false;
			if (w[pivot] > val)
			{
				i--;
				break;
			}
		}
	}
	return true;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> k;
		
		for (int i = 0; i < n; i++)
			cin >> w[i];
		for (int i = 0; i < k; i++)
			cin >> s[i];
		int l = 0, r = 200000;
		while (l < r)
		{
			int m = (l + r) / 2;
			if (check(m))
				r = m;
			else
				l = m + 1;
		}
		cout << "#"  << test_case << " " << r << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}