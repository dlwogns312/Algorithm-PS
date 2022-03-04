#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define min(a,b) a<b?a:b
#define INF 999999999

using namespace std;

int n, m;
int arr[10001] = { 0, };
int now = (1<<26)-1;

int check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if ((arr[i]|now)==now)
			cnt++;

	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			arr[i] |= 1 << (str[j] - 'a');
	}

	int temp;
	char ch;
	while (m--)
	{
		cin >> temp >> ch;
		switch (temp)
		{
		case 1: now -= 1 << (ch - 'a'); break;
		case 2: now += 1 << (ch - 'a'); break;
		}

		cout << check() << "\n";
	}
	
	return 0;
}