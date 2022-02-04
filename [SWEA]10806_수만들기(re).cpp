#include<iostream>

using namespace std;
int n;
int save[11];
int k;

typedef struct node
{
	int left;
	int cnt;
}node;

node arr[9000];
int nodecnt;

bool cmp(node a, node b)
{
	if (a.cnt == b.cnt)
		return a.left < b.left;
	else return a.cnt < b.cnt;
}
void push(int left, int cnt)
{
	arr[nodecnt].left = left;
	arr[nodecnt++].cnt = cnt;

	int temp = nodecnt - 1;

	while (temp > 0&&!cmp(arr[(temp-1)/2],arr[temp]))
	{
		node cur = arr[(temp - 1) / 2];
		arr[(temp - 1) / 2] = arr[temp];
		arr[temp] = cur;
		temp = (temp - 1) / 2;
	}
}

node pop()
{
	node ret = arr[0];
	arr[0] = arr[--nodecnt];

	int cur = 0;

	while (cur * 2 + 1 < nodecnt)
	{
		int child;
		if (cur * 2 + 2 == nodecnt)
			child = cur * 2 + 1;
		else
		{
			if (cmp(arr[cur * 2 + 1], arr[cur * 2 + 2]))
				child = cur * 2 + 1;
			else
				child = cur * 2 + 2;
		}

		if (cmp(arr[cur], arr[child]))
			break;

		node temp = arr[cur];
		arr[cur] = arr[child];
		arr[child] = temp;
		cur = child;
	}

	return ret;
	
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> save[i];
		cin >> k;
		nodecnt = 0;

		push(k, 0);
		int result;
		while (nodecnt > 0)
		{
			node temp = pop();
			int cnt = temp.cnt;
			int left = temp.left;

			if (!left)
			{
				cout << "#" << test_case << " " << cnt << "\n";
				break;
			}
			int check = 0;
			for (int i = 0; i < n; i++)
			{
				if (left >= save[i])
				{
					push(left / save[i], cnt + (left % save[i]));
					check = 1;
				}
			}
			if (!check)
				push(0, cnt + left);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}