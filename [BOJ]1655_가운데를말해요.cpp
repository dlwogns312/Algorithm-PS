#include<iostream>

using namespace std;
int n;
int mincnt=0;
int maxcnt=0;
int minheap[500001];
int maxheap[500001];


void max_push(int num)
{
	maxheap[maxcnt++] = num;

	int cur = maxcnt - 1;

	while (cur > 0 && maxheap[cur] > maxheap[(cur - 1) / 2])
	{
		int temp = maxheap[cur];
		maxheap[cur] = maxheap[(cur-1)/2];
		maxheap[(cur - 1) / 2] = temp;
		cur = (cur - 1) / 2;
	}
}

void min_push(int num)
{
	minheap[mincnt++] = num;
	int cur = mincnt - 1;

	while (cur > 0 && minheap[cur] < minheap[(cur - 1) / 2])
	{
		int temp = minheap[cur];
		minheap[cur] = minheap[(cur - 1) / 2];
		minheap[(cur - 1) / 2] = temp;
		cur = (cur - 1) / 2;
	}
}

int max_pop()
{
	int ret = maxheap[0];
	maxheap[0] = maxheap[--maxcnt];

	int cur = 0;
	while (cur*2+1<maxcnt)
	{
		int child;
		
		if (cur * 2 + 2 == maxcnt)
			child = cur * 2 + 1;
		else
			child = maxheap[cur * 2 + 1] > maxheap[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;
		
		if (maxheap[cur] > maxheap[child])
			break;

		int temp = maxheap[cur];
		maxheap[cur] = maxheap[child];
		maxheap[child] = temp;
		cur = child;
	}

	return ret;
}

int min_pop()
{
	int ret = minheap[0];
	minheap[0] = minheap[--mincnt];

	int cur = 0;
	while (cur * 2 + 1 < mincnt)
	{
		int child;

		if (cur * 2 + 2 == mincnt)
			child = cur * 2 + 1;
		else
			child = minheap[cur * 2 + 1] < minheap[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;

		if (minheap[cur] < minheap[child])
			break;

		int temp = minheap[cur];
		minheap[cur] = minheap[child];
		minheap[child] = temp;
		cur = child;
	}

	return ret;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int temp;
	n--;
	cin >> temp;
	max_push(temp);
	cout << maxheap[0]<<"\n";
	while (n--)
	{
		cin >> temp;
		if (temp > maxheap[0])
			min_push(temp);
		else
			max_push(temp);

		if (mincnt > maxcnt)
			max_push(min_pop());
		else if (maxcnt > mincnt + 1)
			min_push(max_pop());
		
		cout << maxheap[0] << "\n";
	}
	return 0;
}