#include<iostream>
#include<queue>

using namespace std;
int n,l;

typedef struct node
{
	int num;
	int when;
}node;

struct cmp {
	bool operator()(node a, node b)
	{
		if (a.num == b.num)
			return a.when < b.when;
		else return a.num > b.num;
	}
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	priority_queue<node,vector<node>,cmp>pq;

	int temp;
	node temp_node;
	int check;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		temp_node.num = temp;
		temp_node.when = i + 1;
		pq.push(temp_node);

		check = i - l + 2;
		if (check <= 0)
			check = 1;
		while (pq.top().when < check)
		{
			pq.pop();
		}
		cout << pq.top().num << " ";
	}
	cout << "\n";
	return 0;
}