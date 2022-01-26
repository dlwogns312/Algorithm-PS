#include<iostream>
#include<vector>
#include<memory>
#include<cmath>

#define MAX_NUM 1000000000000;

using namespace std;

int n;
vector<pair<int, int>>v;
long long arr[1001][1001];

int visited[1001];

long long dist(int a, int b, int c, int d)
{
	return (a - c) * (a - c) + (b - d) * (b - d);
}

int prim()
{
	long long result = 0;

	visited[0] = 1;
	int toselect = 0;
	long long select_min = MAX_NUM;

	for (int j = 1; j < n; j++)
	{
		if (select_min > arr[0][j])
		{
			select_min = arr[0][j];
			toselect = j;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		visited[toselect] = 1;
		result += select_min;
	
		select_min = MAX_NUM;
		int temp = toselect;
		for (int j = 1; j < n; j++)
		{
			if (visited[j])
				continue;
			arr[0][j] = min(arr[0][j], arr[temp][j]);

			
			if (select_min > arr[0][j])
			{
				select_min = arr[0][j];
				toselect = j;
			}
		}	
	}

	return result;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cout << fixed;
	cout.precision(0);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		v.resize(n);
		int a;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v[i].first = a;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v[i].second = a;
		}

		for (int i = 0; i < n; i++)
		{
			arr[i][i] = 0;
			visited[i] = 0;
			for (int j = i; j < n; j++)
			{
				long  long temp = dist(v[i].first, v[i].second, v[j].first, v[j]. second);
				arr[i][j] = temp;
				arr[j][i] = temp;
			}
		}

		double temp;

		cin >> temp;
		
		cout << "#" << test_case << " " << (double)(temp*prim()) << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}