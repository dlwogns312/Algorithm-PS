#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

struct enemy
{
	int i, j;
};

struct arc
{
	int dist, enemy_num;
};

int enemy_cnt = 0;
using namespace std;
int n, m, d;
int result = 0;


int dist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}
void solution(int first, int second, int third, vector<int> _save,enemy _enemy_node[])
{
	vector<int> save;
	save.assign(_save.begin(), _save.end());

	int died[300] = { 0, };
	enemy enemy_node[300];
	for (int i = 0; i < enemy_cnt; i++)
		enemy_node[i] = _enemy_node[i];
	for (int i = 0; i < n; i++)
	{
		arc first_kill, second_kill, third_kill;

		first_kill.dist = 9999;
		second_kill.dist = 9999;
		third_kill.dist = 9999;
		for (int j = 0; j < save.size(); j++)
		{
			if (died[save[j]])
				continue;
			int temp;
			temp = dist(n, first, enemy_node[save[j]].i, enemy_node[save[j]].j);

			if (temp < first_kill.dist&&temp<=d)
			{
				first_kill.dist = temp;
				first_kill.enemy_num = save[j];
			}

			temp = dist(n, second, enemy_node[save[j]].i, enemy_node[save[j]].j);

			if (temp < second_kill.dist&&temp<=d)
			{
				second_kill.dist = temp;
				second_kill.enemy_num = save[j];
			}

			temp = dist(n, third, enemy_node[save[j]].i, enemy_node[save[j]].j);

			if (temp < third_kill.dist&&temp<=d)
			{
				third_kill.dist = temp;
				third_kill.enemy_num = save[j];
			}

			enemy_node[save[j]].i++;
			if (enemy_node[save[j]].i >= n)
				died[save[j]] = 2;
		}
		if (first_kill.dist != 9999)
			died[first_kill.enemy_num] = 1;
		if (second_kill.dist != 9999)
			died[second_kill.enemy_num] = 1;
		if (third_kill.dist != 9999)
			died[third_kill.enemy_num] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < enemy_cnt; i++)
	{
		if (died[i] == 1)
			cnt++;
	}
	result = max(cnt, result);
}

enemy enemy_node[300];

bool cmp(int i, int j)
{
	return enemy_node[i].j < enemy_node[j].j;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> d;

	int temp;
	vector<int> save;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			if (temp)
			{
				enemy_node[enemy_cnt].i = i;
				enemy_node[enemy_cnt].j = j;
				save.push_back(enemy_cnt++);
			}
		}

	sort(save.begin(), save.end(), cmp);

	for (int i = 0; i < m-2; i++)
	{
		for (int j = i + 1; j < m - 1; j++)
		{
			for (int x = j + 1; x < m; x++)
			{
				solution(i, j, x,save,enemy_node);
			}
		}
	}

	cout << result << "\n";
	return 0;

}