#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int arr[3][3];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str = "";
	
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++) {
			char temp;
			cin >> temp;
			str += temp;
		}

	set<string> chk;
	queue<pair<string, int>> q;
	chk.insert(str);
	q.push(make_pair(str, 0));

	int result = -1;

	while (!q.empty())
	{
		string now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == "123456780")
		{
			result = cnt;
			break;
		}

		int start = now.find('0');

		int x = start / 3; int y = start % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				string next = now;

				swap(next[3 * x + y], next[nx * 3 + ny]);

				if (chk.find(next) == chk.end())
				{
					chk.insert(next);
					q.push(make_pair(next, cnt + 1));
				}
			}
		}
	}

	cout << result << "\n";
}