#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int main()
{
	int t, m;
	cin >> t;

	while (t--)
	{
		cin >> m;
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		vector<int> result;

		cout << (m + 1) / 2 << "\n";
		int temp;
		int max_size = 0, min_size = 0;
		
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			if (i == 0)
			{
				max_heap.push(temp);
				max_size++;
			}
			else
			{
				if (max_heap.top() < temp)
				{
					min_heap.push(temp);
					min_size++;
				}
				else
				{
					max_heap.push(temp);
					max_size++;
				}
			}
			if (i % 2 == 0)
			{
				if (max_size > min_size + 1)
				{
					min_size++; max_size--;
					min_heap.push(max_heap.top());
					max_heap.pop();
				}
				else if (min_size > max_size)
				{
					min_size--; max_size++;
					max_heap.push(min_heap.top());
					min_heap.pop();
				}
				result.push_back(max_heap.top());
			}
		}

		for (int i = 0; i < (m + 1) / 2; i++)
		{
			if (i % 10 == 0 && i != 0)
				cout << "\n";
			cout << result[i] << " ";
		}
	}
}