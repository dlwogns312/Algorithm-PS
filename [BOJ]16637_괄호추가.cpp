#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int result = -987654321;
int n;
string str;

int cal(int i, int j, char oper)
{
	int ret = i;
	switch (oper)
	{
	case '+':ret += j; break;
	case'-':ret -= j; break;
	case'*':ret *= j; break;
	}
	return ret;
}
void dfs(int idx, int cur)
{
	if (idx >= n)
	{
		result = max(result, cur);
		return;
	}

	char op = idx >= 1 ? str[idx - 1] : '+';
	
	if (idx + 2 < n)
	{
		int temp = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, cal(cur, temp, op));
	}
	dfs(idx + 2, cal(cur, str[idx] - '0', op));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> str;

	dfs(0, 0);
	cout << result << "\n";
}