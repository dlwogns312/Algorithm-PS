#include<iostream>
#include<vector>

using namespace std;

#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int test_case;
	int T;

	cin >> T;

	vector<pair<int, int>> v;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int l, n;
		cin >> l;
		cin >> n;
		int result = 0;

		v.resize(n);
		int a, b;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			v[i] = { a,b };
		}


		int res = 0, target = 0;

		for (int i = 0; i < n && result != l; i++)
		{
			int pos = v[i].first;
			int temp = 0;
			for (; target < n; target++)
			{
				if (v[target].second <= pos + l)
				{
					res += v[target].second - v[target].first;
					continue;
				}
				if (v[target].first < pos + l)
				{
					temp += pos + l - v[target].first;

				}
				break;
			}
			result = max(result, res + temp);
			if (target > i)
				res -= v[i].second - v[i].first;
			else
				target++;
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}