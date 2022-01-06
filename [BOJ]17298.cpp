#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
#include <stack>
using namespace std;

typedef struct node
{
	int data;
	int idx;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	int* result;

	result = (int*)calloc(n, sizeof(int));

	stack<node> save;

	node n_temp;
	n_temp.data = v[0];
	n_temp.idx = 0;

	save.push(n_temp);
	for (int i = 1; i < n; i++)
	{
		while (!save.empty()&&save.top().data < v[i])
		{
			result[save.top().idx] = v[i];
			save.pop();
		}
		n_temp.data = v[i];
		n_temp.idx = i;
		save.push(n_temp);
	}

	for (int i = 0; i < n; i++)
		if (result[i])
			cout << result[i] << " ";
		else
			cout << -1 << " ";


	

}