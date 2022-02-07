#include<iostream>
#include<cstring>

#define H_size (1<<18)
#define Maxn 100000
#define div (H_size-1)

using namespace std;

char b[500001], s[100001];
int p[100001];
int n, m;

void findp()
{
	p[0] = 0;
	for (int i = 1; s[i]; i++)
	{
		int j = p[i - 1];
		while (j > 0&&s[i]!=s[j])
		{
			j = p[j - 1];
		}
		if (s[i] == s[j])
			p[i] = j + 1;
		else p[i] = 0;
	}
}

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
		findp();
		
		int result = 0, piv = 0, cnt = 0;
		while (b[piv])
		{
			if (b[piv] == s[cnt])
			{
				if (!s[cnt + 1])
				{
					result++;
					cnt = p[cnt];
				}
				else
					cnt++;
				piv++;
			}
			else if (cnt > 0)
				cnt = p[cnt - 1];
			else
				piv++;
		}
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}