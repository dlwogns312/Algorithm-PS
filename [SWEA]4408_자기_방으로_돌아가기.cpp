#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int a, b;
		int count = 0;
		cin >> n;

		vector<pair<int, int>> v;


	for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a > b)
				v.push_back(make_pair(b, a));
			else
				v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end(), compare);

		while (!v.empty())
		{
			int fin = v[0].second;
			v.erase(v.begin());

			count++;
			if (fin % 2)
				fin++;
			fin /= 2;
			for (int i = 0; i < v.size(); i++)
			{
				if ((v[i].first+1)/2 > fin)
				{
					fin = v[i].second;
					v.erase(v.begin() + i);
					fin = (fin + 1) / 2;
					i--;
				}
			}
		}

		cout << "#" << test_case << " " << count << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}