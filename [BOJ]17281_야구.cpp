#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int result = 0;
int n;
int Select[10], order[10];
int hit[51][10];
int when = 0;
void play()
{
	when++;
	int score=0;
	int now_hit = 1;
	int out_cnt;
	int home[4] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		out_cnt = 0;
		while (out_cnt<3)
		{
			if (hit[i][order[now_hit]] == 1)
			{
				if (home[3])
					score++;
				home[3] = home[2];
				home[2] = home[1];
				home[1] = 1;
			}
			else if (hit[i][order[now_hit]] == 2)
			{
				if (home[3])
					score++;
				if (home[2])
					score++;
				home[3] = home[1];
				home[2] = 1;
				home[1] = 0;
			}
			else if (hit[i][order[now_hit]] == 3)
			{
				if (home[3])
					score++;
				if (home[2])
					score++;
				if (home[1])
					score++;
				home[3] = 1;
				home[2] = 0;
				home[1] = 0;
			}
			else if (hit[i][order[now_hit]] == 4)
			{
				if (home[3])
					score++;
				if (home[2])
					score++;
				if (home[1])
					score++;
				score++;
				memset(home, 0, sizeof(home));
			}
			else
			{
				out_cnt++;
			}
			now_hit++;
			if (now_hit == 10)
				now_hit = 1;
		}
		memset(home, 0, sizeof(home));
	}
	result = max(result, score);
}
void dfs(int cnt)
{
	if (cnt == 10)
	{
		play();
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (Select[i])
			continue;
		Select[i]=1;
		order[i] = cnt;
		dfs(cnt + 1);
		Select[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < 10; j++)
			cin >> hit[i][j];

	memset(Select, 0, sizeof(Select));
	Select[4] = 1;
	order[4] = 1;

	dfs(2);

	cout << result << "\n";
}