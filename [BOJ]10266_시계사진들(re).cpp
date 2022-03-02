#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int fail[360000] = { 0 ,};
string a="", b="";

void makefail()
{
	for (int i = 1, j = 0; i < 360000; i++)
	{
		while (j > 0 && b[i] != b[j])
		{
			j = fail[j - 1];
		}
		if (b[i] == b[j])
			fail[i] = ++j;
	}
}
bool kmp()
{
	for (int i = 0, j = 0; i <a.length(); i++)
	{
		while (j > 0 && a[i] != b[j])
			j = fail[j - 1];
		if (a[i] == b[j])
		{
			if (j == 360000 - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 360000; i++)
	{
		a += "0"; b += "0";
	}

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a[temp] = '1';
	}

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		b[temp] = '1';
	}

	makefail();
	a+=a;
	bool result = kmp();

	if (result)
		cout << "possible\n";
	else
		cout << "impossible\n";
	return 0;
}