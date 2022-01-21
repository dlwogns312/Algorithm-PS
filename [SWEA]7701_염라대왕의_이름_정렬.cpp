#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<string> v;
string save[20001];

void conquer(int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (v[i].length() < v[j].length())
			save[k++] = v[i++];
		else if (v[i].length() == v[j].length())
		{
			if (v[i] < v[j])
				save[k++] = v[i++];
			else
				save[k++] = v[j++];
		}
		else
			save[k++] = v[j++];
	}

	if (i > m)
		while (j <= r)
			save[k++] = v[j++];
	else
		while (i <= m)
			save[k++] = v[i++];

	for (i = l; i <= r; i++)
		v[i] = save[i];
}
void merge(int l, int r)
{
	int m;

	if (l < r)
	{
		m = (l + r) / 2;
		merge(l, m);
		merge(m + 1, r);
		conquer(l, m, r);
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	string temp;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		merge(0, v.size() - 1);

		cout << "#" << test_case << "\n";
		cout << v[0] << "\n";
		for (int i = 1; i < v.size(); i++)
		{

			if (v[i] != v[i - 1])
				cout << v[i] << "\n";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}