#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

#define MAXN 1010

using namespace std;

//slime structure
typedef struct
{
	int x, y;
}slime;

//save the slime information
int slime_num = 0;
slime node[10001];

int n, d;
char arr[MAXN][MAXN];
int ret = 0;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < n;
}

void slime_eat(slime s, int add,int dir)
{
	add--;

	if (dir == 0)
	{
		for (int i = s.x - add+1; i < s.x + add; i++)
		{
			if (arr[i][s.y + add] != 'S')
			{
				arr[i][s.y + add] = 'S';
				ret++;
			}
		}

		if (arr[s.x - add][s.y + add] != 'S')
		{
			arr[s.x - add][s.y + add] = 'S';
			ret++;
		}
		if (arr[s.x + add][s.y + add] != 'S')
		{
			arr[s.x + add][s.y + add] = 'S';
			ret++;
		}
	}
	else if (dir == 1)
	{
		for (int i = s.y - add+1; i < s.y + add; i++)
		{
			if (arr[s.x + add][i] != 'S')
			{
				arr[s.x + add][i] = 'S';
				ret++;
			}
		}

		if (arr[s.x + add][s.y - add] != 'S')
		{
			arr[s.x + add][s.y - add] = 'S';
			ret++;
		}
		if (arr[s.x + add][s.y + add] != 'S')
		{
			arr[s.x + add][s.y + add] = 'S';
			ret++;
		}
	}
	else if (dir == 2)
	{
		for (int i = s.y - add+1; i < s.y + add; i++)
		{
			if (arr[s.x - add][i] != 'S')
			{
				arr[s.x - add][i] = 'S';
				ret++;
			}
		}

		if (arr[s.x - add][s.y - add] != 'S')
		{
			arr[s.x - add][s.y - add] = 'S';
			ret++;
		}
		if (arr[s.x - add][s.y + add] != 'S')
		{
			arr[s.x - add][s.y + add] = 'S';
			ret++;
		}
	}
	else
	{
		for (int i = s.x - add+1; i < s.x + add; i++)
		{
			if (arr[i][s.y - add] != 'S')
			{
				arr[i][s.y - add] = 'S';
				ret++;
			}
		}

		if (arr[s.x - add][s.y - add] != 'S')
		{
			arr[s.x - add][s.y - add] = 'S';
			ret++;
		}
		if (arr[s.x + add][s.y - add] != 'S')
		{
			arr[s.x + add][s.y - add] = 'S';
			ret++;
		}
	}

	if (add < 0)
	{
		if (arr[s.x][s.y] != 'S')
		{
			arr[s.x][s.y] = 'S';
			ret++;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = s.x + dx[i] * (add + 1), ny = s.y + dy[i] * (add + 1);
			if (arr[nx][ny] != 'S')
			{
				arr[nx][ny] = 'S';
				ret++;
			}
		}
	}
}

bool slime_check(slime s, int add)
{
	add--;
	//위, 아래쪽 체크
	for (int i = s.y - add+1; i < s.y + add; i++)
	{
		if (!move(s.x-add,i)||!move(s.x+add,i)||arr[s.x - add][i] == '#' || arr[s.x + add][i] == '#')
			return false;
	}

	//좌,우 체크
	for (int i = s.x - add + 1; i < s.x + add; i++)
	{
		if (!move(i,s.y-add)||!move(i,s.y+add)||arr[i][s.y - add] == '#' || arr[i][s.y + add] == '#')
			return false;
	}

	//각 튀어나온 부분 확인
	for (int i = 0; i < 4; i++)
	{
		int nx = s.x + dx[i] * (add + 1), ny = s.y + dy[i] * (add + 1);
		if (!move(nx,ny)||arr[nx][ny] == '#')
		{
			return false;
		}
	}

	//증식 가능하기 때문에 농작물 먹는다.
	//위, 아래쪽 체크
	for (int i = s.y - add + 1; i < s.y + add; i++)
	{
		if (arr[s.x - add][i] == '.')
		{
			arr[s.x - add][i] = 'S';
			ret++;
		}
		if(arr[s.x + add][i] == '.')
		{
			arr[s.x + add][i] = 'S';
			ret++;
		}
	}

	//좌,우 체크
	for (int i = s.x - add + 1; i < s.x + add; i++)
	{
		if (arr[i][s.y - add] == '.')
		{
			arr[i][s.y - add] = 'S';
			ret++;
		} 
		if(arr[i][s.y + add] == '.')
		{
			arr[i][s.y + add] = 'S';
			ret++;
		}
	}

	//각 튀어나온 부분 확인
	for (int i = 0; i < 4; i++)
	{
		int nx = s.x + dx[i] * (add + 1), ny = s.y + dy[i] * (add + 1);
		if (arr[nx][ny] == '.')
		{
			arr[nx][ny] = 'S';
			ret++;
		}
	}
	return true;
}

void slime_move(slime s, int time, int add)
{
	//slime_eat(s, add,prev);
	
	//증식
	if (time == d)
	{
		bool live=slime_check(s, ++add);
		if (!live)
			return;
		time = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = s.x + dx[i], ny = s.y + dy[i];
		if (slime_check({ nx,ny }, add))
			slime_move({ nx,ny }, time+1,add);
	}
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}
int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				node[slime_num].x = i;
				node[slime_num++].y = j;
				ret++;
			}
		}

	for (int i = 0; i < slime_num; i++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nx = node[i].x + dx[x], ny = node[i].y + dy[x];

			if (move(nx,ny)&&slime_check({nx,ny},0))		
				slime_move({ nx,ny }, 1, 0);
			
		}
	}

	//print();
	cout << ret;
}
