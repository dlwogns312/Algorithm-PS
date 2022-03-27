#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

int T, l;
int visited[300][300];
int now_i, now_j, to_i, to_j;
int cnt;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

void bfs()
{
	queue<pair<int,pair<int, int>>> q;
	q.push({ 0,{ now_i,now_j} });

	int temp_i, temp_j,temp;

	while (!q.empty())
	{
		temp_i = q.front().second.first;
		temp_j = q.front().second.second;
		temp = q.front().first;

		q.pop();

		if (temp_i == to_i && temp_j == to_j)
		{
			cnt = temp;
			break;
		}
		if (visited[temp_i][temp_j])
			continue;
		visited[temp_i][temp_j] = 1;
		
		for (int i = 0; i < 8; i++)
		{
			int nx = temp_i + dx[i];
			int ny = temp_j + dy[i];

			if (nx >= 0 && ny >= 0 && nx < l && ny < l)
				q.push({ temp + 1,{ nx,ny} });
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> l;
		cin >> now_i >> now_j;
		cin >> to_i >> to_j;
		cnt = 0;
		memset(visited, 0, sizeof(visited));

		bfs();
		cout << cnt<< "\n";
	}



}