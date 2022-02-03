
#include<iostream>

#define mod 20171109

using namespace std;
int n;
int maxheap[200002];
int minheap[200001];
int maxcnt, mincnt;

void addmax(int num)
{
	int pivot = maxcnt;
	maxheap[maxcnt++] = num;

	while (pivot > 0)
	{
		int pp = pivot;
		pivot = pivot - 1 >> 1;
		if (maxheap[pivot] < num)
		{
			maxheap[pp] = maxheap[pivot];
			maxheap[pivot] = num;
		}
		else return;
	}
}

void addmin(int num)
{
	int pivot = mincnt;
	minheap[mincnt++] = num;

	while (pivot > 0)
	{
		int pp = pivot;
		pivot = pivot - 1 >> 1;
		if (minheap[pivot] > num)
		{
			minheap[pp] = minheap[pivot];
			minheap[pivot] = num;
		}
		else return;
	}
}

int popmax()
{
	int num = maxheap[0];
	maxheap[0] = maxheap[--maxcnt];

	int pivot = 0;
	while (1)
	{
		int pp = pivot;
		pivot = (pivot << 1) + 1;

		if (maxcnt <= pivot)
			break;
		if (maxcnt == pivot + 1)
		{
			if (maxheap[pivot] > maxheap[pp])
			{
				int temp = maxheap[pivot];
				maxheap[pivot] = maxheap[pp];
				maxheap[pp] = temp;
			}
			else break;
		}
		else
		{
			if (maxheap[pivot] < maxheap[pivot + 1])
				pivot++;
			if (maxheap[pivot] > maxheap[pp])
			{
				int temp = maxheap[pivot];
				maxheap[pivot] = maxheap[pp];
				maxheap[pp] = temp;
			}
			else break;
		}
	}
	return num;
}

int popmin()
{
	int num = minheap[0];
	minheap[0] = minheap[--mincnt];

	int pivot = 0;
	while (1)
	{
		int pp = pivot;
		pivot=(pivot << 1) + 1;

		if (mincnt <= pivot)break;
		if (mincnt == pivot + 1)
		{
			if (minheap[pivot] < minheap[pp])
			{
				int temp = minheap[pivot];
				minheap[pivot] = minheap[pp];
				minheap[pp] = temp;
			}
			else break;
		}
		else
		{
			if (minheap[pivot] > minheap[pivot + 1])
				pivot++;
			if (minheap[pivot] < minheap[pp])
			{
				int temp = minheap[pivot];
				minheap[pivot] = minheap[pp];
				minheap[pp] = temp;
			}
			else break;
		}
	}

	return num;
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
		int a, b;
		
		maxcnt = mincnt = 0;
		cin >> n >> a;
	
		addmax(a);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a > maxheap[0])
				addmin(a);
			else addmax(a);
			if (b > maxheap[0])
				addmin(b);
			else addmax(b);
			if (maxcnt < mincnt)
				addmax(popmin());
			else if (maxcnt - 1 > mincnt)
				addmin(popmax());
			sum = (sum + maxheap[0]) % mod;
		}
		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}