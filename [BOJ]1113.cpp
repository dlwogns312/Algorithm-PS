#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <vector<int>> v(52, vector<int>(52, 0));
int n, m;
int maximum = 0;
int ret = 0;

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { 1,0,-1,0 };

queue<pair<int, int>> q;

void bfs(int i)
{
    q.push({ 0,0 });
    v[0][0] = i;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int nx, ny;
        for (int j = 0; j < 4; j++)
        {
            nx = x + dir_x[j];
            ny = y + dir_y[j];
            if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && v[nx][ny] < i)
            {
                v[nx][ny] = i;
                q.push({ nx,ny });
            }
        }
    }
}

void settlement(int i)
{
    for(int x=1;x<=n;x++)
        for (int y = 1; y <= m; y++)
            if (v[x][y] < i)
            {
                ret++;
                v[x][y]++;
            }

}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            scanf("%1d", &tmp);
            v[i][j] = tmp;
            maximum = max(maximum, tmp);
        }

    
    for (int i = 0; i <= maximum; i++)
    {
        bfs(i);
        settlement(i);
    }

    cout << ret << "\n";

}