#include<iostream>
#include<cstring>

typedef long long ll;

#define time 3

using namespace std;

ll save[2001][2001],power[4000000],dp[2001];

int h,w,n, m;

char ori[2001][2001], teacher[2001][2001];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;

	cin >> T;
	
	int result;
	
	power[0] = 1;
	for (int i = 1; i < 4000001; i++)
		power[i] = power[i - 1] * time;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> h >> w >> n >> m;
		ll num = 0;

		for (int i = 0; i < h; i++)
		{
			cin >> ori[i];
		}

	
		for (int i = 0; i < n; i++)
		{
			cin >> teacher[i];
		}

		int result = 0;
		ll temp;
		for (int i = 0; i < n; i++)
		{
			temp = 0;
			for (int j = 0; j < w; j++)
				if (teacher[i][j] == 'o')
					temp += power[w - j - 1];
			save[i][w - 1] = temp;

			for (int j = w; j < m; j++)
			{
				if (teacher[i][j - w] == 'o')
					save[i][j] = save[i][j - 1] - power[w - 1];
				else
					save[i][j] = save[i][j - 1];
				save[i][j] = save[i][j] * time;
				if(teacher[i][j]=='o')
					save[i][j]+= 1;
			}
		}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (ori[i][j] == 'o')
					num += power[w * (h - i) - j - 1];

		for (int i = w - 1; i < m; i++)
		{
			dp[i] = 0;
			for (int j = 0; j < h; j++)
				dp[i] += save[j][i] * power[w * (h - j - 1)];
			if (num == dp[i])
				result++;
		}

		for (int i = 1; i < n - h + 1; i++)
		{
			for (int j = w - 1; j < m; j++)
			{
				dp[j] = (dp[j] - save[i - 1][j] * power[w * (h - 1)]) * power[w] + save[i + h - 1][j];
				if (num == dp[j])
					result++;
			}
		}
		
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}