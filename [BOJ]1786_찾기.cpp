#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int fail[1000000] = { 0, };
int result[100000];
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string t, p;

	getline(cin, t);
	getline(cin, p);

	int word = p.length();

	for (int i = 1, j = 0; i < word; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = fail[j - 1];
		if (p[i] == p[j])
			fail[i] = ++j;
		else
			fail[i] = 0;
	}

	for (int i = 0, j = 0; i < t.length(); i++)
	{
		while (j > 0 && t[i] != p[j])
			j = fail[j - 1];
		if (t[i] == p[j])
		{
			if (j == word -1 )
			{
				result[cnt++] = i - word + 1;
				j = fail[j];
			}
			else
				j++;
		}
		else
			j = 0;
	}

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << result[i] +1 << " ";
	cout << "\n";
}