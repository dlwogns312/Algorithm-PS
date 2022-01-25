int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int arr[10][10];

#define min(a,b) a<b?a:b

typedef struct node
{
    int x;
    int y;
}node;

void bfs_init(int map_size, int map[10][10]) {
    for (int i = 0; i < map_size; i++)
        for (int j = 0; j < map_size; j++)
            arr[i][j] = map[i][j];

}
int bfs(int x1, int y1, int x2, int y2) {
    int visited[10][10] = { 0, };

    node save[101] = { 0, };
    int result[10][10];

    int front = 0,count=0;

    int ret = -1;

    save[count].x = x1-1;
    save[count++].y = y1-1;

    visited[y1-1][x1-1] = 1;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            result[i][j] = 100;

    result[y1 - 1][x1 - 1] = 0;

    while (count > 0&&front<=count)
    {
        int temp_x = save[front].x;
        int temp_y = save[front++].y;

        if (temp_x == x2 - 1 && temp_y == y2 - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int check_x = temp_x + dx[i];
            int check_y = temp_y + dy[i];

            if (check_x >= 0 && check_y >= 0 && check_x < 10 && check_y < 10&&!visited[check_y][check_x]&&!arr[check_y][check_x])
            {
                result[check_y][check_x] = result[temp_y][temp_x] + 1;
                visited[check_y][check_x] = 1;
                save[count].x = check_x;
                save[count++].y = check_y;
            }
        }
    }
    if (result[y2-1][x2-1] == 100)
        return -1;
    else
        return result[y2-1][x2-1];
}