#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int arr[1001][1001] = { 0, };
int dir[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char a[1000], b[1000];

	cin >> a;
	cin >> b;

	int i, j;
	for (i = 1; b[i-1]; i++)
	{
		for (j = 1; a[j-1]; j++)
		{
			if (a[j-1] == b[i-1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
				dir[i][j] = 2;
			}
			else
			{
				if (arr[i - 1][j] > arr[i][j - 1])
				{
					dir[i][j] = 0;
					arr[i][j] = arr[i - 1][j];
				}
				else
				{
					dir[i][j] = 1;
					arr[i][j] = arr[i][j - 1];
				}
			}
		}
	}

	stack<char>st;

	i--; j--;
	while (arr[i][j])
	{
		switch (dir[i][j])
		{
		case 0:i--; break;
		case 1:j--; break;
		case 2:st.push(b[i - 1]); i--; j--; break;
		}
	}
	
	cout << st.size() << "\n";
	int num = st.size();
	if (num)
	{
		for (int i = 0; i < num; i++)
		{
			cout << st.top();
			st.pop();
		}
	}
	return 0;

}