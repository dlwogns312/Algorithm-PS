#include<iostream>
#include<cstring>
using namespace std;

int n, k;
int arr[14][14];
int visited[14][14];
int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {1,-1,0,0};

struct _node {
	int dir;
	int i, j;
	int move;
	int top;
}node[11];

//play 함수
int play()
{
	int ret = 0;
	for (int i = 1; i <= k; i++)
	{
		if(!node[i].move)
		{
			ret++;
			continue;
		}
		
		//파란색
		int temp_x = node[i].i + dir_x[node[i].dir];
		int temp_y = node[i].j + dir_y[node[i].dir];
		if (arr[temp_x][temp_y] == 2)
		{
			switch (node[i].dir)
			{
			case 0:node[i].dir = 1; break;
			case 1:node[i].dir = 0; break;
			case 2:node[i].dir = 3; break;
			case 3:node[i].dir = 2; break;
			}
			
			int test_x = node[i].i + dir_x[node[i].dir];
			int test_y = node[i].j + dir_y[node[i].dir];
			
			if (arr[test_x][test_y] == 2)
				continue;
			temp_x = node[i].i + dir_x[node[i].dir];
			temp_y = node[i].j + dir_y[node[i].dir];
		}

		visited[node[i].i][node[i].j] = 0;
		//흰색
		if (arr[temp_x][temp_y] == 0)
		{
			if (visited[temp_x][temp_y] == 0)
			{
				visited[temp_x][temp_y] = i;
				node[i].i = temp_x;
				node[i].j = temp_y;
			}
			else
			{
				int tmp = visited[temp_x][temp_y];
				node[tmp].top = node[i].top;
				node[i].move = 0;
			}
		}
		else if (arr[temp_x][temp_y] == 1)
		{
			//빨간색
			if (visited[temp_x][temp_y] == 0)
			{
				visited[temp_x][temp_y] = node[i].top;
				node[node[i].top].top = i;
				node[i].move = 0;
				node[node[i].top].move = 1;
				node[node[i].top].i = temp_x;
				node[node[i].top].j = temp_y;
				
			}
			else
			{
				int tmp = visited[temp_x][temp_y];
				node[tmp].top = i;
				node[i].move = 0;
			}
		}
		
	}

	if (ret < n - 1)
		return 0;
	else
		return 1;
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << visited[i][j] << " ";
		cout << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	memset(visited, 0, sizeof(visited));
	//체스 판 입력
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	//체스 판 초기화
	for (int i = 0; i <= n + 1; i++)
	{
		arr[i][0] = 2;
		arr[0][i] = 2;
		arr[i][n + 1] = 2;
		arr[n + 1][i] = 2;
	}

	//체스 말 입력
	for (int i = 1; i <= k; i++)
	{
		cin >> node[i].i >> node[i].j >> node[i].dir;
		node[i].dir--;
		visited[node[i].i][node[i].j] = i;
		node[i].move = 1;
		node[i].top = i;
		node[i].move = 1;
	}

	int ret;
	
	for (ret = 0; ret <= 1000; ret++)
	{
		if (play())
			break;
		print();
		cout << "\n";
	}

	if (ret > 1000)
		cout << -1 << "\n";
	else
		cout << ret << "\n";

	return 0;
	
}