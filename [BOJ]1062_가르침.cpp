#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define max(a,b) a>b?a:b

using namespace std;

int n, k;
vector<string>v;
int result = 0;
int temp = 0;

int check()
{
	int cnt = 0;
	int right;
	for (int i = 0; i < v.size(); i++)
	{
		right = 1;
		for (int j = 0; j < v[i].length(); j++)
		{
			if (!((1 << (v[i][j] - 'a')) & temp))
			{
				right = 0;
				break;
			}
		}
		if (right)
			cnt++;
	}

	return cnt;
}
void dfs(int cur, int alph)
{
	if (alph == k)
	{
		result = max(result, check());
		return;
	}
	
	for (int i = cur; i < 26; i++)
	{
		if (temp & (1 << i))
			continue;
		temp |= (1 << i);
		dfs(i, alph + 1);
		temp -= (1 << i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	string save;
	for (int i = 0; i < n; i++)
	{
		cin >> save;
		v.push_back(save);
	}

	temp|=1 << ('a' - 'a');
	temp |= 1 << ('n' - 'a'); temp |= 1 << ('t' - 'a'); temp |= 1 << ('i' - 'a'); temp |= 1 << ('c' - 'a');

	if(k>=5)
		dfs(0,5);
	
	cout << result << "\n";
	return 0;
}