#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;

struct _node
{
	int fin_time, reception_num;
	int reception_time, repair_time;
}node[1001];

struct comp
{
	bool operator()(const int& a, const int& b)const
	{
		if (node[a].fin_time != node[b].fin_time)
			return node[a].fin_time > node[b].fin_time;
		return node[a].reception_num > node[b].reception_num;
	}
};
int ret;
int reception[21], repair[21];
int using_recep[21], using_repair[21];
int n, m, k, a, b,done_num;
int customer[1001],cur_cust;
priority_queue<int,vector<int>,greater<>> empty_reception, empty_repair;

void execute(int x,priority_queue<int,vector<int>,comp>& repair_pq)
{
	for (int i = 0; i < n; i++)
	{
		if (using_recep[i] == -1)
			continue;
		int tmp = using_recep[i];
		node[tmp].reception_time--;
		if (node[tmp].reception_time == 0)
		{
			node[tmp].fin_time = x;
			repair_pq.push(tmp);
			using_recep[i] = -1;
			empty_reception.push(i);
		}
	}

	for (int j = 0; j < m; j++)
	{
		if (using_repair[j] == -1)
			continue;
		int tmp = using_repair[j];
		node[tmp].repair_time--;
		if (node[tmp].repair_time == 0)
		{
			done_num++;
			if (node[tmp].reception_num == a - 1 && j == b - 1)
			{
				ret += (tmp + 1);
				//cout << tmp + 1 << " ";
			}
			using_repair[j] = -1;
			empty_repair.push(j);
		}
	}
}

int main()
{
	int tc;
	
	//freopen("input.txt", "r", stdin);
	cin >> tc;


	for (int i = 1; i <= tc; i++)
	{
		//Initialize
		done_num = 0;
		ret = 0;
		cin >> n >> m >> k >> a >> b;
		priority_queue<int, vector<int>, comp>repair_pq;
		priority_queue<int,vector<int>, greater<>>reception_pq;
		empty_reception = empty_repair = priority_queue<int, vector<int>,greater<>>();
		memset(customer, -1, sizeof(customer));

		for (int x = 0; x < n; x++)
		{
			cin >> reception[x];
			using_recep[x] = -1;
			empty_reception.push(x);
		}
		for (int x = 0; x < m; x++)
		{
			cin >> repair[x];
			using_repair[x] = -1;
			empty_repair.push(x);
		}
		for (int x = 0; x < k; x++)
			cin >> customer[x];
		cur_cust = 0;
		
		for (int x = customer[0]; done_num != k; x++)
		{
			while (customer[cur_cust] == x)
			{
				reception_pq.push(cur_cust++);
			}

			while (!empty_reception.empty())
			{
				if (reception_pq.empty())
					break;

				int tmp_empty = empty_reception.top(), tmp = reception_pq.top();
				empty_reception.pop(); reception_pq.pop();

				using_recep[tmp_empty] = tmp;
				node[tmp].reception_num = tmp_empty;
				node[tmp].reception_time = reception[tmp_empty];
			}

			while (!empty_repair.empty())
			{
				if (repair_pq.empty())
					break;
				
				int tmp_empty = empty_repair.top(), tmp = repair_pq.top();
				empty_repair.pop(); repair_pq.pop();

				using_repair[tmp_empty] = tmp;
				node[tmp].repair_time = repair[tmp_empty];
			}
			execute(x,repair_pq);
		}

		if (!ret)
			ret = -1;
				
		cout << "#" << i << " " << ret << "\n";
		
	}
}