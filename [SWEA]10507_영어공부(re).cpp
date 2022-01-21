#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define max(a,b) a>b?a:b
int result;
int visit[1000001];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	vector<int>v;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, p,max;
		cin >> n >> p;
		v.resize(n);
		result = 0;
		int temp = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			visit[v[i]] = 1;
			temp = max(temp, v[i]);
		}
		result = p + 1;


		int start = 1, end = 1, count = 0;

		while (end < 1000001)
		{
			if (visit[end])
			{
				count++;
				end++;
				result = max(result, count);
			}
			else
			{
				if (!p)
				{
					result = max(result, count);
					if (!visit[start])
						p++;
					start++;
					count--;
				}
				else
				{
					p--;
					count++;
					end++;
				}
			}
		}

		cout << "#" << test_case << " " << result << "\n";



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}