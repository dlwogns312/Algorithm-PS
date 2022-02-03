
#include<iostream>

using namespace std;
int n;
int arr[100001];
int result[100001];
int cnt;

void push(int num)
{
	arr[cnt] = num;

	int cur = cnt;
	while (cur > 0 && arr[cur] > arr[(cur - 1) / 2])
	{
		int temp = arr[(cur - 1) / 2];
		arr[(cur - 1) / 2] = arr[cur];
		arr[cur] = temp;
		cur = (cur - 1) / 2;
	}

	cnt++;
}

int pop()
{
	if (cnt <= 0)
		return -1;

	int value = arr[0];
	cnt--;
	arr[0] = arr[cnt];

	int cur = 0;

	while (cur * 2 + 1 < cnt)
	{
		int child;
		if (cur * 2 + 2 == cnt)
			child = cur * 2 + 1;
		else
			child = arr[cur * 2 + 1] > arr[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;

		if (arr[cur] > arr[child])
			break;

		int temp = arr[cur];
		arr[cur] = arr[child];
		arr[child]=temp;
		cur = child;
	}

	return value;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	int a, b;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		cnt = 0;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == 1)
			{
				cin >> b;
				push(b);
			}
			else if (a == 2)
			{
				result[res++] = pop();
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < res; i++)
			cout << result[i] << " ";
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}