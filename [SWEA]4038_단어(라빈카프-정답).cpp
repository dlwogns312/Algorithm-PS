#include<iostream>
#include<cstring>

typedef long long ll;

using namespace std;

char b[500001], s[100001];

int n, m;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;

	cin >> T;

	int result;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> b >> s;
		result = 0;
		ll com[5] = { 0, };
		ll temp[5] = { 0, };
		ll mod[5] = { 1,1,1,1,1 };

		int s_len = strlen(s), b_len = strlen(b);
		int flag;
		for (int i = 0; i < b_len - s_len + 1; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < s_len; j++)
				{
					for (int x = 0; x < 5; x++)
					{
						com[x] += s[s_len - 1 - j] * mod[x];
						temp[x] += b[s_len - 1 - j] * mod[x];
					}
					if (j < s_len - 1)
						for (int x = 0; x < 5; x++)
							mod[x] *= (x + 1);
				}
			}
			else {
				for (int j = 0; j < 5; j++)
				{
					temp[j] = (j + 1) * (temp[j] - b[i - 1] * mod[j]) + b[s_len - 1 + i];
				}
			}
			flag = 1;
			for (int j = 0; j < 5; j++)
				if (temp[j] != com[j])
					flag = 0;
			if (flag)
				result++;
		}
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}