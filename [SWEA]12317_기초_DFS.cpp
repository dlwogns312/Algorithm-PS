int child[100][5];
int count[100];


void dfs_init(int N, int path[100][2])
{
	for (int i = 0; i < 100; i++)
		count[i] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		child[path[i][0]][count[path[i][0]]++] = path[i][1];
	}
}

int real(int king, int n)
{
	int ret = -1;

	for (int i = 0; i < count[n]; i++)
	{
		if (child[n][i] > king)
			return child[n][i];
		ret = real(king, child[n][i]);
		if (ret > king)
			return ret;
	}

	return ret;
}
int dfs(int n)
{
	return real(n,n);
}
