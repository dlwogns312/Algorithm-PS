#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

typedef struct tree
{
	int parent;
	int left;
	int right;
}tree;

int check[10001];
vector<tree>v;

int DFS(int cur)
{
	int ret = 1;
	
	if (v[cur].left)
		ret += DFS(v[cur].left);
	if (v[cur].right)
		ret += DFS(v[cur].right);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int T;
	
	cin >> T;
	int n;
	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(check, 0, sizeof(check));

		

		int a, b;
		int V, e;
		cin >> V >> e >> a >> b;

		v.resize(V + 1);
		for (int i = 1; i < V + 1; i++)
			v[i].parent =v[i].left = v[i].right = 0;
		int temp,child;

		for (int i = 0; i < e; i++)
		{
			cin >> temp >> child;
			if (!v[temp].left)
				v[temp].left = child;
			else
				v[temp].right = child;

			v[child].parent = temp;
		}

		temp = v[a].parent;
		while (1)
		{
			check[temp] = 1;

			if (temp == 1)
				break;
			temp = v[temp].parent;
		}

		temp = v[b].parent;
		while (1)
		{
			if (check[temp])
			{
				cout << "#" << test_case << " " << temp<<" " << DFS(temp) << "\n";
				break;
			}
			temp = v[temp].parent;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}